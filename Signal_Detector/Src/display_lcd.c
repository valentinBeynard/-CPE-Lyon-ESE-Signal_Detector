/*
 * display_lcd.c
 *
 *  Created on: Jun 5, 2019
 *      Author: BEYNARD
 */
#include "display_lcd.h"
#include "stm32746g_discovery_lcd.h"


#define PLOT_X	20
#define PLOT_Y	40
#define PLOT_WIDTH	(RK043FN48H_WIDTH - 40)
#define PLOT_HEIGHT	200

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

void Init_Display(void)
{
	BSP_LCD_Init();

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
	BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"KiCAD Team Bitch !", CENTER_MODE);
	BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"Drivers examples", CENTER_MODE);
}


void Display_Render(void)
{
	/* Clear the LCD */
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);

	/* Set the LCD Text Color */
	BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);

	/* Main Analyzer Title */
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"CPE Lyon : Raw Signal !", CENTER_MODE);

	/* Plot Background */
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_FillRect(PLOT_X, PLOT_Y, PLOT_WIDTH, PLOT_HEIGHT);

	Plot_Signal(signal_test_buffer, SIGNAL_BUFF);
}

void Plot_Signal(uint16_t *buffer, uint16_t nbr_pts)
{
	float pts1 = 0;
	float pts2 = 0;
	float time_step = 0;

	time_step = PLOT_WIDTH / ((float)nbr_pts);

	/* Set the LCD Text Color */
	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);

	for(uint16_t i = 0 ; i < nbr_pts ; i++)
	{
		/*
		pts1 = buffer[i];
		pts2 = buffer[i + 1];

		pts1 = (1 - (pts1 / 0xFFFF));
		pts2 = (1 - (pts2 / 0xFFFF));

		pts1 = PLOT_Y + pts1 * PLOT_HEIGHT;
		pts1 = PLOT_Y + pts2 * PLOT_HEIGHT;

		BSP_LCD_DrawLine(PLOT_X + (int)(time_step * i), (int)(pts1), PLOT_X +  (int)(time_step * (i+1)), (int)(pts2));
		*/
		pts1 = buffer[i];
		pts1 = (pts1 / 0xFFF);
		pts1 = (1 - pts1);

		pts1 = PLOT_Y + pts1 * PLOT_HEIGHT;

		BSP_LCD_DrawPixel(PLOT_X + (int)(time_step * i), (int)(pts1), LCD_COLOR_YELLOW);


	}
}
