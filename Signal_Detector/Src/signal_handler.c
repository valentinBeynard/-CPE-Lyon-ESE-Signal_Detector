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

volatile uint32_t sampling_buff[SAMPLES_NBR];
uint8_t is_ready;

uint8_t raw_signal[SAMPLES_NBR];
uint8_t ref_signal[SAMPLES_NBR];
uint8_t corr_func[2 * SAMPLES_NBR - 1];
uint8_t ref_sampled;
uint8_t result_ready;
uint8_t corr_max;
uint16_t sample_corr_max;

uint8_t ref_threshold = 1.0;

uint8_t signal_detected = 0;

//volatile SAMPLES_PCK samples_pck = { {0}, 0};
//
//SIGNALS_PCK signals_pck =
//			{
//					{0},
//					{0},
//					0,
//					0,
//					0,
//					0
//			};


uint8_t display_ready = 0;

/*
##########################################################################
			INTERRUPT HANDLERS
##########################################################################
*/

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	is_ready = 1;
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
	HAL_ADC_Start_DMA(hadc1, sampling_buff, SAMPLES_NBR);

}

void signal_handler_process()
{
	if(is_ready == 1)
	{
		signals_analyse();
		display_ready = 1;
		is_ready = 0;
	}
}

void signals_analyse()
{
	if(ref_sampled == 0)
	{
		//memset(ref_signal, sampling_buff, SAMPLES_NBR);
		for(int i = 0 ; i < SAMPLES_NBR ; i++)
		{
			ref_signal[i] = sampling_buff[i];
		}
		crosscorrelation(ref_signal, ref_signal);
		ref_threshold = corr_max;
		ref_sampled = 1;
	}
	else
	{
		//strncpy(raw_signal, sampling_buff, SAMPLES_NBR);

		for(int i = 0 ; i < SAMPLES_NBR ; i++)
		{
			raw_signal[i] = sampling_buff[i];//sampling_buff[i];
		}

		crosscorrelation(ref_signal, raw_signal);
		search_signal();

	}


}

void search_signal()
{
	uint16_t th = (THRESHOLD_RATIO * ref_threshold);
	if(signal_detected == 0)
	{
		if(corr_max >= th)
		{
			signal_detected = 1;
		}
	}
	else
	{
		if(corr_max < th)
		{
			signal_detected = 0;
		}
	}
}



void crosscorrelation(uint8_t* target, uint8_t* input_signal)
{

	uint32_t i,j,k;
	int p = SAMPLES_NBR + SAMPLES_NBR -1;


	float x_signal[p];
	float target_signal[p];
	uint32_t x_norm = 0;
	uint32_t target_norm = 0;

	float correlation[p];
	uint32_t shift = 0;
	uint32_t a = 0;

	uint32_t norm = 0;

	uint16_t min_w = 0;
	uint16_t max_w = 0;

	/*
	min_w = (uint16_t)( (p/2) - 200);
	max_w = (uint16_t)( (p/2) + 200);
	sample_corr_max = (uint16_t)( (p/2));*/


	/* Reverse Signal Array to perform correlation x(n-l) */
	/* and remove offset for each signals */
	for(j=0 ; j < p; j++)
	{

		/* Supress Offsets */
		if(j < SAMPLES_NBR)
		{
			/* Suppress X Signal Offset */

			x_signal[j] = (float)(( input_signal[j] - 0x7F))/0x7F;
			x_norm += x_signal[j] * x_signal[j];

			/* Suppress Ref Signal Offset */
			target_signal[j] = (float)((target[j] - 0x7F))/0x7F;
			target_norm += target_signal[j] * target_signal[j];
		}
		else
		{
			x_signal[j] = 0;
			target_signal[j] = 0;
		}
	}

	correlation[0]=0;


	/* Perform all correlation(n) calculs */
	corr_max = corr_func[0];

	for(i = 0 ; i < p ; i++)
	{
		correlation[i] = 0;
		/* Compute correlation(n) */
		for(j = 0 ; j < p ; j++)
		{
			a = p - ((shift + j) % p);
			correlation[i] += x_signal[j] * target_signal[p - ((shift + j) % p)];
		}

		if(correlation[i] > corr_max)
		{
			corr_max = correlation[i];
			sample_corr_max = i;
		}
		shift++;

	}

	for(i = 0 ; i < p ; i++)
	{
		corr_func[i] =  (uint8_t)(0xFF * ( (float)(abs(correlation[i])) / ref_threshold));
	}


}

uint8_t can_display()
{
	return display_ready;
}

void disable_signal_display()
{
	display_ready = 0;
}

uint8_t get_threshold()
{
	return THRESHOLD_RATIO * ref_threshold;
}

uint8_t is_signal_here()
{
	return signal_detected;
}

uint8_t* get_signal_data(SIGNAL_ID id)
{
	uint8_t* ret = 0;

	switch(id)
	{
	case INPUT:
		ret = raw_signal;
		break;
	case REF:
		ret = ref_signal;
		break;
	default:
		ret = (corr_func + sample_corr_max - 200);
		//ret = (corr_func + (sample_corr_max - 200));
		break;
	}

	return ret;
}

