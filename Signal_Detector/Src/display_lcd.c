/*
 * display_lcd.c
 *
 *  Created on: Jun 5, 2019
 *      Author: BEYNARD
 */
#include "display_lcd.h"
#include "stdio.h"




#define SIGNAL_BUFF	256

const uint16_t signal_test_buffer[SIGNAL_BUFF] = {
	2048,2098,2148,2198,2248,2298,2348,
2398,2447,2496,2545,2594,2642,2690,2737,
2785,2831,2877,2923,2968,3013,3057,3100,
3143,3185,3227,3267,3307,3347,3385,3423,
3460,3496,3531,3565,3598,3631,3662,3692,
3722,3750,3778,3804,3829,3854,3877,3899,
3920,3940,3958,3976,3992,4007,4021,4034,
4046,4056,4065,4073,4080,4086,4090,4093,
4095,4095,4095,4093,4090,4086,4080,4073,
4065,4056,4046,4034,4021,4007,3992,3976,
3958,3940,3920,3899,3877,3854,3829,3804,
3778,3750,3722,3692,3662,3631,3598,3565,
3531,3496,3460,3423,3385,3347,3307,3267,
3227,3185,3143,3100,3057,3013,2968,2923,
2877,2831,2785,2737,2690,2642,2594,2545,
2496,2447,2398,2348,2298,2248,2198,2148,
2098,2048,1997,1947,1897,1847,1797,1747,
1697,1648,1599,1550,1501,1453,1405,1358,
1310,1264,1218,1172,1127,1082,1038,995,
952,910,868,828,788,748,710,672,635,599,
564,530,497,464,433,403,373,345,317,291,
266,241,218,196,175,155,137,119,103,88,
74,61,49,39,30,22,15,9,5,2,0,0,0,2,5,9,
15,22,30,39,49,61,74,88,103,119,137,155,
175,196,218,241,266,291,317,345,373,403,
433,464,497,530,564,599,635,672,710,748,
788,828,868,910,952,995,1038,1082,1127,
1172,1218,1264,1310,1358,1405,1453,1501,
1550,1599,1648,1697,1747,1797,1847,1897,1947,
1997 };

static TS_StateTypeDef  TS_State;

GUI_Button button_list[NUMBER_OF_BUTTON] =
						{ {0, INPUT_SIGNAL_X, INPUT_SIGNAL_Y, NORMAL_BUTTON_WIDTH, NORMAL_BUTTON_HEIGHT, LCD_COLOR_DARKMAGENTA, INPUT_LABEL},
							{0, REF_SIGNAL_X, REF_SIGNAL_Y, NORMAL_BUTTON_WIDTH, NORMAL_BUTTON_HEIGHT, LCD_COLOR_DARKCYAN, REF_LABEL},
							{0, CORR_SIGNAL_X, CORR_SIGNAL_Y, NORMAL_BUTTON_WIDTH, NORMAL_BUTTON_HEIGHT, LCD_COLOR_DARKYELLOW, CORR_LABEL}
						};


uint8_t detection_label[32] = "Signals : ";

PLOT_ID plot_id = INPUT_PLOT;

//if(GPIO_Pin == TS_INT_PIN)
//  {

//
//  }

void Init_Display(void)
{
	BSP_LCD_Init();

	/* Initialize TouchScreen in Interrupts Mode */
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);

	/* Set LCD Foreground Layer  */
	BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

	/* Enable LCD Display */
	BSP_LCD_DisplayOn();


	/* Clear the LCD */
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);


	/* Set the LCD Text Color */
	BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);

	/* Display LCD messages */
	//BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"KiCAD Team Bitch !", CENTER_MODE);
	//BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"Drivers examples", CENTER_MODE);
}


void Display_Render(void)
{
	/* Clear the LCD */
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	//BSP_LCD_Clear(LCD_COLOR_WHITE);

	/* Set the LCD Text Color */
	BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);

	/* Main Analyzer Title */
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"CPE Lyon : Raw Signal !", CENTER_MODE);

	/* Plot Background */
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(PLOT_X, PLOT_Y, PLOT_WIDTH, PLOT_HEIGHT);

	//Plot_Signal((uint8_t*)signal_test_buffer, SIGNAL_BUFF);
}

void Draw_GUI(void)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(GUI_X, GUI_Y, GUI_WIDTH, GUI_HEIGHT);

	for(int i = 0; i < NUMBER_OF_BUTTON ; i++)
	{
		BSP_LCD_SetTextColor(button_list[i].color);
		if(button_list[i].is_active == 0)
		{
			BSP_LCD_DrawRect(button_list[i].x_pos, button_list[i].y_pos, button_list[i].width, button_list[i].height);
		}
		else
		{
			BSP_LCD_FillRect(button_list[i].x_pos, button_list[i].y_pos, button_list[i].width, button_list[i].height);
		}
		BSP_LCD_SetFont(&Font8);
		BSP_LCD_DisplayStringAt(button_list[i].x_pos + 15, button_list[i].y_pos + 15, button_list[i].text, LEFT_MODE);
	}

	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTCYAN);
	BSP_LCD_FillRect(DETEC_CNT_X, DETEC_CNT_Y, DETEC_CNT_WIDTH, DETEC_CNT_HEIGHT);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font8);
	BSP_LCD_DisplayStringAt(DETEC_CNT_X + 10, DETEC_CNT_Y + 10, detection_label, LEFT_MODE);

}

void Plot_Signal(uint8_t *buffer, uint16_t nbr_pts)
{
	float pts1 = 0;
	float time_step = 0;

	time_step = 1;

	/* Clear Last Signal */
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(PLOT_X, PLOT_Y, PLOT_WIDTH, PLOT_HEIGHT);
	BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
	BSP_LCD_FillRect(PLOT_X - 5, PLOT_Y - 5, PLOT_WIDTH + 10, PLOT_HEIGHT + 10);

	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);

	for(uint16_t i = 0 ; i < nbr_pts ; i++)
	{
		pts1 = buffer[i];
		pts1 = (pts1 / 0xFF);
		pts1 = (1 - pts1);

		pts1 = PLOT_Y + pts1 * PLOT_HEIGHT;

		BSP_LCD_DrawPixel(PLOT_X + (uint16_t)(time_step * i), (uint16_t)(pts1), LCD_COLOR_YELLOW);

	}


}

void Plot_Threshold(float th_ratio)
{

	BSP_LCD_SetTextColor(LCD_COLOR_RED);

	BSP_LCD_DrawLine(PLOT_X, (uint16_t)(PLOT_Y + (1- th_ratio) * PLOT_HEIGHT), PLOT_X + PLOT_WIDTH, (uint16_t)(PLOT_Y + (1- th_ratio) * PLOT_HEIGHT));
}

void Draw_Signal_Marker(SIGNAL_STATE signal_state)
{
	if(signal_state == SIGNAL_HERE)
	{
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
	}
	else
	{
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
	}

	BSP_LCD_FillCircle(15, 15, 10);

}

void Draw_Sampling_Target_Marker()
{
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGREEN);
	BSP_LCD_FillCircle(40, 15, 10);
}

void Update_Signal_Labal_Cnt(uint16_t cnt)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_FillRect(DETEC_CNT_X, DETEC_CNT_Y, DETEC_CNT_WIDTH, DETEC_CNT_HEIGHT);

	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTCYAN);
	BSP_LCD_FillRect(DETEC_CNT_X, DETEC_CNT_Y, DETEC_CNT_WIDTH, DETEC_CNT_HEIGHT);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font8);

	sprintf(detection_label, "Signals : %d", cnt);
	BSP_LCD_DisplayStringAt(DETEC_CNT_X + 10, DETEC_CNT_Y + 10, detection_label, LEFT_MODE);
}

void active_button(uint8_t index)
{
	for(int j = 0 ; j < NUMBER_OF_BUTTON ; j++)
	{
		if(j != index)
		{
			button_list[j].is_active = 0;
		}
		else{
			button_list[j].is_active = 1;
			plot_id = j;
		}
	}
}

void TouchScreen_Polling(void)
{
	static uint8_t t = 0;
	uint16_t x = 0;
	uint16_t y = 0;

	BSP_TS_GetState(&TS_State);

	if(TS_State.touchDetected)
	{
		x = TS_State.touchX[0];
		y = TS_State.touchY[0];

		for(int i = 0; i < NUMBER_OF_BUTTON ; i++)
		{
			if(x > button_list[i].x_pos && x < (button_list[i].x_pos + button_list[i].width))
			{
				if(y > button_list[i].y_pos && y < (button_list[i].y_pos + button_list[i].height))
				{
					active_button(i);
					Draw_GUI();
				}
			}
		}


	}
}

PLOT_ID get_current_plot_ID()
{
	return plot_id;
}
