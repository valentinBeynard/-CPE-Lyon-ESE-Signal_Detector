#include "../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.h"
#include "../Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.h"
#include "LCDScreen_generation.h"
#include "stm32f7xx_hal.h"
//#include "Generation_son.h"

static TS_StateTypeDef  TS_State;

uint8_t id_freq;
uint8_t id_harmonique;

uint8_t button_freq;
uint8_t button_harmonique;

Button button_list[5]={{0,plotx,ploty,width_button,height_button,LCD_COLOR_DARKYELLOW,"466.0 Hz"},
			{0,plotx+width_button+20,ploty,width_button,height_button,LCD_COLOR_DARKYELLOW,"440 Hz"},
			{0,plotx+2*width_button+40,ploty,width_button,height_button,LCD_COLOR_DARKYELLOW,"587.4 Hz"},
			{0,plotx,ploty+height_button+20,width_button,height_button,LCD_COLOR_DARKYELLOW,"784 Hz"},
			{0,plotx+width_button+20,ploty+height_button+20,width_button,height_button,LCD_COLOR_DARKYELLOW,"1318.8Hz"}};

Button harmonique[3]={{0,plotx,ploty+2*(height_button+20),width_button,height_button,LCD_COLOR_BLUE,"1"},
		{0,plotx+width_button+20,ploty+2*(height_button+20),width_button,height_button,LCD_COLOR_BLUE,"2"},
		{0,plotx,ploty+3*(height_button+20),width_button,height_button,LCD_COLOR_BLUE,"3"},
};
void Init_LCD(void)
{

  BSP_LCD_Init();
  BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
  BSP_LCD_DisplayOn();
  /* Clear the LCD */
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);


	/* Set the LCD Text Color */
	BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);


}


void Draw_Button(void)
{
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	for(int i = 0; i < number_button; i++)
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

	for (int i=0;i<3;i++)
	{
		BSP_LCD_SetTextColor(harmonique[i].color);
		if(harmonique[i].is_active==0)
		{
			BSP_LCD_DrawRect(harmonique[i].x_pos, harmonique[i].y_pos, harmonique[i].width, harmonique[i].height);
		}
		else {
			BSP_LCD_FillRect(harmonique[i].x_pos, harmonique[i].y_pos, harmonique[i].width, harmonique[i].height);
		}
		BSP_LCD_SetFont(&Font8);
		BSP_LCD_DisplayStringAt(harmonique[i].x_pos + 15, harmonique[i].y_pos + 15, harmonique[i].text, LEFT_MODE);

	}

}


void TouchScreen_Polling(void)
{
	uint16_t x = 0;
	uint16_t y = 0;


	BSP_TS_GetState(&TS_State);

	if(TS_State.touchDetected)
	{
		x = TS_State.touchX[0];
		y = TS_State.touchY[0];

		for(int i = 0; i < number_button ; i++)
		{
			if(x > button_list[i].x_pos && x < (button_list[i].x_pos + button_list[i].width))
			{
				if(y > button_list[i].y_pos && y < (button_list[i].y_pos + button_list[i].height))
				{
					button_freq=i;
				}
			}
		}
		for(int i = 0; i < 3 ; i++)
		{
			if(x > harmonique[i].x_pos && x < (harmonique[i].x_pos + harmonique[i].width))
			{
				if(y > harmonique[i].y_pos && y < (harmonique[i].y_pos + harmonique[i].height))
				{
					button_harmonique=i;
				}
			}
		}
		Active_Button(button_freq,button_harmonique);
		Draw_Button();
		Signal();
	}
}


void Active_Button(uint8_t index,uint8_t index2)
{
	for(int j = 0 ; j < number_button; j++)
	{
		if(j != index)
		{
			button_list[j].is_active = 0;
		}
		else{
			button_list[j].is_active = 1;
			id_freq=j;
		}
	}
	for (int i=0;i<3;i++)
	{
		if (i!=index2)
		{
			harmonique[i].is_active=0;
		}
		else {
			harmonique[i].is_active=1;
			id_harmonique=i;
		}

	}
}

void Signal()
{
	float frequence;
	uint8_t nbr_harmonique;
	switch(id_freq){

		case (0):
			//frequence=261.6;
			frequence=466.0;
		break ;

		case(1):
			frequence=440;
		break;

		case (2):
			frequence=587.4;
			break ;

		case(3):
			frequence=784;
			break;
		case(4):
			frequence=1318.8;
		break;
		default:
			frequence = 440;
			break;
	}

	switch(id_harmonique)
	{

		case(0):
			nbr_harmonique=1;
		break;

		case(1):
			nbr_harmonique=2;
		break;

		case(2):
			nbr_harmonique=3;
		break;
	}

	Generate_signal((uint16_t)frequence,nbr_harmonique);
}
