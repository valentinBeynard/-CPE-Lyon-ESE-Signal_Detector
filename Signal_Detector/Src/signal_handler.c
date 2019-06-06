/*
 * signal_handler.c
 *
 *  Created on: Jun 6, 2019
 *      Author: BEYNARD
 */
#include "signal_handler.h"



/*
##########################################################################
			USER VARIABES
##########################################################################
*/

uint8_t atest[SAMPLES_NBR];

volatile SAMPLES_PCK samples_pck = { {0}, 0};

SIGNALS_PCK signals_pck =
			{
					{0},
					{0},
					{0},
					0,
					0,
					0
			};


uint8_t display_ready = 0;

/*
##########################################################################
			INTERRUPT HANDLERS
##########################################################################
*/

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	samples_pck.is_ready = 1;
}


/*
##########################################################################
			CORE FUNCTIONS
##########################################################################
*/

void Init_Sampling(ADC_HandleTypeDef * hadc1)
{
//	samples_pck = (SAMPLES_PCK*) malloc(sizeof(SAMPLES_PCK));
//
//	for(int i = 0 ; i < SAMPLES_NBR; i++)
//	{
//		samples_pck->sampling_buff[i] = 0;
//	}
//	samples_pck->is_ready = 0;
//
//	signals_pck = (SIGNALS_PCK*) malloc(sizeof(SIGNALS_PCK));
//	for(int i = 0 ; i < SAMPLES_NBR; i++)
//	{
//		signals_pck->raw_signal[i] = 0;
//		signals_pck->ref_signal[i] = 0;
//		signals_pck->corr_func[i] = 0;
//	}
//	signals_pck->corr_max = 0;
//	signals_pck->ref_sampled = 0;
//	signals_pck->result_ready = 0;
//	signals_pck->sample_corr_max = 0;

	HAL_ADC_Start(hadc1);
	HAL_ADC_Start_DMA(hadc1, samples_pck.sampling_buff, SAMPLES_NBR);

}

void signal_handler_process()
{
	if(samples_pck.is_ready == 1)
	{
		signals_analyse();
		display_ready = 1;
		samples_pck.is_ready = 0;
	}
}

void signals_analyse()
{
	if(signals_pck.ref_sampled == 0)
	{
		//strncpy(signals_pck.ref_signal, samples_pck.sampling_buff, SAMPLES_NBR);
		for(int i = 0 ; i < SAMPLES_NBR ; i++)
		{
			signals_pck.ref_signal[i] = 0;//samples_pck.sampling_buff[i];
		}
		signals_pck.ref_sampled = 1;
	}
	else
	{
		strncpy(signals_pck.raw_signal, samples_pck.sampling_buff, SAMPLES_NBR);

		//crosscorrelation(signals_pck.ref_signal, signals_pck.raw_signal);


	}


}

void crosscorrelation(uint8_t* ref_signal, uint8_t* comp_signal)
{

	int i,j,k;
	int p = SAMPLES_NBR + SAMPLES_NBR -1;

	float comp_f[p],comp_f_2[p], ref_signal_2[p],comp_signal_2[p];
	float y[p];
	float somme_ref,somme_comp;
	float norm;

	/*Copy signals*/
	/* Pad the smaller sequence with zero*/

	comp_signal_2[0] = (float)((comp_signal[0] - 0x88))/0x88;
	ref_signal_2[0] = (float)((ref_signal[0] - 0x88))/0x88;

	somme_ref=ref_signal_2[0]*ref_signal_2[0];
	somme_comp=comp_signal_2[0]*comp_signal_2[0];

	/* Reverse Signal Array to perform correlation x(n-l) */
	/* and remove offset for each signals */
	for(j=1;j<SAMPLES_NBR;j++){
		comp_signal_2[j] = (float)((comp_signal[j] - 0x88))/0x88;
		somme_comp+=comp_signal_2[j]*comp_signal_2[j];
		ref_signal_2[j] = (float)((ref_signal[j] - 0x88))/0x88;
		somme_ref+=ref_signal_2[j]*ref_signal_2[j];
	}
	for(i= SAMPLES_NBR ;i<p;i++){
		comp_signal_2[i]=0;
	}
	for(i= SAMPLES_NBR;i<p;i++){
		ref_signal_2[i]=0;
	}

  /*folding h(n) to h(-n)*/
	y[0]=0;
	comp_f[0]=comp_signal_2[0];
	/* Reverse Signal Array to perform correlation x(n-l) */
	/* and remove offset for each signals */
	for(j=1;j<p;j++){ /*folding h(n) to h(-n)*/
		comp_f[j]=comp_signal_2[p-j];
	}

	/*Circular convolution*/
	for(i=0;i<p;i++){
		y[0] += ref_signal_2[i] * comp_f[i];
	}


	for(k=1;k<p;k++)
	{
		y[k]=0;

		/*circular shift*/
		for(j=1;j<p;j++){
			comp_f_2[j] = comp_f[j-1];
		}

		comp_f_2[0] = comp_f[p-1];

		/*Circular convolution*/
		for(i=0;i<p;i++)
		{
			comp_f[i] = comp_f_2[i];
			y[k] += ref_signal_2[i] * comp_f_2[i];
		}

	}


		/* Normalize Correlation function */
		norm = (float) (sqrt(somme_ref) * sqrt(somme_comp));
		for(k = 0 ; k < p ; k++)
		{
			y[k] = 0x88 * (y[k]/ norm) + 0x88;
			signals_pck.corr_func[k] = (uint8_t) ( y[k] );
			signals_pck.corr_func[k] = 0xFF * signals_pck.corr_func[k];
		}

		signals_pck.corr_max = signals_pck.corr_func[0];

		//l=0;

		for(k=1;k<p;k++)
		{
			if(signals_pck.corr_func[k] > signals_pck.corr_max)
			{
				signals_pck.corr_max = signals_pck.corr_func[k];
				signals_pck.sample_corr_max = k;
				//l=k;
			}

		}

}

uint8_t can_display()
{
	return display_ready;
}

uint8_t disable_signal_display()
{
	display_ready = 0;
}

uint8_t* get_signal_data(SIGNAL_ID id)
{
	uint8_t* ret = 0;

	switch(id)
	{
	case INPUT:
		ret = signals_pck.raw_signal;
		break;
	case REF:
		ret = signals_pck.ref_signal;
		break;
	default:
		ret = (signals_pck.corr_func + (signals_pck.sample_corr_max - 200));
		break;
	}

	return ret;
}

