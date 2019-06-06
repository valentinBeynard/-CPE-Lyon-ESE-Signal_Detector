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




/*
##########################################################################
			INTERRUPT HANDLERS
##########################################################################
*/

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	display_ready = 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance==TIM7)
	{


		if (nb_acquisition==0){
				reference[i]=adc_last_value;
		}else{
				comparaison[i]=adc_last_value;

				/* Add value in buffer for displaying */
				display_buff[display_buff_ptr] = adc_last_value;
				display_buff_ptr++;

				/* Indicate display_buff ready for displaying */
				if( display_buff_ptr >= PLOT_WIDTH)
				{
					display_buff_ptr = 0;
					display_ready = 1;
					//HAL_TIM_Base_Stop_IT(&htim7);
				}

		}

		i++;
		if (i>= M_signal_pts){
			HAL_TIM_Base_Stop_IT(&htim7);
			//HAL_ADC_Stop(&hadc1);
			if (nb_acquisition>0){
				//crosscorrelation(reference,reference);
			}
			nb_acquisition++;
			declencher_acquisition();
		}

//		HAL_ADC_Start(&hadc1);
//
//		HAL_ADC_PollForConversion(&hadc1,10);
//
//		ADC_value = HAL_ADC_GetValue(&hadc1);
//		if (nb_acquisition==0){
//				reference[i]=ADC_value;
//		}else{
//				comparaison[i]=ADC_value;
//
//				/* Add value in buffer for displaying */
//				display_buff[display_buff_ptr] = ADC_value;
//				display_buff_ptr++;
//
//				/* Indicate display_buff ready for displaying */
//				if( display_buff_ptr >= PLOT_WIDTH)
//				{
//					display_buff_ptr = 0;
//					display_ready = 1;
//					//HAL_TIM_Base_Stop_IT(&htim7);
//				}
//
//		}
//
//		HAL_ADC_Stop(&hadc1);
//		i++;
//		if (i>= M_signal_pts){
//			HAL_TIM_Base_Stop_IT(&htim7);
//			//HAL_ADC_Stop(&hadc1);
//			if (nb_acquisition>0){
//				//crosscorrelation(reference,reference);
//			}
//			nb_acquisition++;
//			declencher_acquisition();
//		}



	}
	else if(htim->Instance==TIM3)
	{
		TouchScreen_Polling();
	}
}

/*
##########################################################################
			CORE FUNCTIONS
##########################################################################
*/

void crosscorrelation(uint8_t* ref_signal, uint8_t* comp_signal)
{

	int i,j,k;
	int p = M_signal_pts + M_signal_pts -1;

	float comp_f[p],comp_f_2[p], ref_signal_2[p],comp_signal_2[p];
	float somme_ref,somme_comp;
	float norm;
	float test = 0;

	/*Copy signals*/
	/* Pad the smaller sequence with zero*/

	comp_signal_2[0] = (float)((comp_signal[0] - 0x88))/0x88;
	ref_signal_2[0] = (float)((ref_signal[0] - 0x88))/0x88;

	somme_ref=ref_signal_2[0]*ref_signal_2[0];
	somme_comp=comp_signal_2[0]*comp_signal_2[0];

	/* Reverse Signal Array to perform correlation x(n-l) */
	/* and remove offset for each signals */
	for(j=1;j<M_signal_pts;j++){
		comp_signal_2[j] = (float)((comp_signal[j] - 0x88))/0x88;
		somme_comp+=comp_signal_2[j]*comp_signal_2[j];
		ref_signal_2[j] = (float)((ref_signal[j] - 0x88))/0x88;
		somme_ref+=ref_signal_2[j]*ref_signal_2[j];
	}
	for(i= M_signal_pts ;i<p;i++){
		comp_signal_2[i]=0;
	}
	for(i= M_signal_pts;i<p;i++){
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
			corr_func[k] = (uint8_t) ( y[k] );
			corr_func[k] = 0xFF * corr_func[k];
		}

		max=corr_func[0];
		l=0;
		for(k=1;k<p;k++)
		{
			if(corr_func[k]>max)
			{
				max=corr_func[k];
				corr_max_abs = k;
				l=k;
			}

		}

}


