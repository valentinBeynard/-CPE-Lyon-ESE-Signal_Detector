/*
 * LCDScreen_generation.h
 *
 *  Created on: Jun 11, 2019
 *      Author: Nathan
 */

#include "main.h"

#ifndef LCDSCREEN_GENERATION_H_
#define LCDSCREEN_GENERATION_H_

#define plotx 20
#define ploty 50

#define height_button 30
#define width_button 100
#define number_button 6

typedef struct
{
	uint8_t is_active;
	uint16_t x_pos;
	uint16_t y_pos;
	uint16_t width;
	uint16_t height;
	uint32_t color;
	uint8_t* text;
}Button;


void Init_LCD();
void Draw_Button();
void Active_Button(uint8_t index,uint8_t index2);
void Signal();
void TouchScreen_Polling();

#endif /* LCDSCREEN_GENERATION_H_ */
