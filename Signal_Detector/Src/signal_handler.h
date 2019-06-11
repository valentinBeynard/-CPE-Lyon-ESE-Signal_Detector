/*
 * signal_handler.h
 *
 *  Created on: Jun 6, 2019
 *      Author: BEYNARD
 */

#ifndef SIGNAL_HANDLER_H_
#define SIGNAL_HANDLER_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define SAMPLES_NBR	1024

#define THRESHOLD_RATIO	0.90

typedef struct
{
	volatile uint8_t sampling_buff[SAMPLES_NBR];
	uint8_t is_ready;
}SAMPLES_PCK;

typedef struct
{
	uint8_t raw_signal[SAMPLES_NBR];
	uint8_t ref_signal[SAMPLES_NBR];
	//uint8_t corr_func[SAMPLES_NBR * SAMPLES_NBR - 1];
	uint8_t ref_sampled;
	uint8_t result_ready;
	uint8_t corr_max;
	uint8_t sample_corr_max;
}SIGNALS_PCK;

typedef enum
{
	INPUT = 0,
	REF,
	CORR
}SIGNAL_ID;

typedef enum
{
	CALIBRATION_STATE = 0,
	INIT_REF,
	IDLE
}FSM_SH_STATE;


void Init_Sampling(ADC_HandleTypeDef * hadc1);
void signal_handler_process(FSM_SH_STATE fsm_state);
void signals_analyse();
uint8_t can_display();
void disable_signal_display();
uint8_t* get_signal_data(SIGNAL_ID id);
void crosscorrelation(uint8_t* target, uint8_t* input_signal , uint16_t min_w, uint16_t max_w);
void xcorr(uint8_t* ref_signal, uint8_t* comp_signal);
void search_signal();
uint8_t get_threshold();
uint8_t is_signal_here();
uint16_t getSignalCnt();
void target_sampling();
void analyse_target();

#endif /* SIGNAL_HANDLER_H_ */
