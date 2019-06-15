/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
//#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Generation_son.h"
#include "LCDScreen_generation.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim7;

///* USER CODE BEGIN PV */
//const uint16_t sine_wave_array[256] = {
//	2048,2098,2148,2198,2248,2298,2348,2398,2447,2496,2545,2594,2642,2690,2737,
//2785,2831,2877,2923,2968,3013,3057,3100,3143,3185,3227,3267,3307,3347,3385,3423,
//3460,3496,3531,3565,3598,3631,3662,3692,3722,3750,3778,3804,3829,3854,3877,3899,
//3920,3940,3958,3976,3992,4007,4021,4034,4046,4056,4065,4073,4080,4086,4090,4093,
//4095,4095,4095,4093,4090,4086,4080,4073,4065,4056,4046,4034,4021,4007,3992,3976,
//3958,3940,3920,3899,3877,3854,3829,3804,3778,3750,3722,3692,3662,3631,3598,3565,
//3531,3496,3460,3423,3385,3347,3307,3267,3227,3185,3143,3100,3057,3013,2968,2923,
//2877,2831,2785,2737,2690,2642,2594,2545,2496,2447,2398,2348,2298,2248,2198,2148,
//2098,2048,1997,1947,1897,1847,1797,1747,1697,1648,1599,1550,1501,1453,1405,1358,
//1310,1264,1218,1172,1127,1082,1038,995,952,910,868,828,788,748,710,672,635,599,
//564,530,497,464,433,403,373,345,317,291,266,241,218,196,175,155,137,119,103,88,
//74,61,49,39,30,22,15,9,5,2,0,0,0,2,5,9,15,22,30,39,49,61,74,88,103,119,137,155,
//175,196,218,241,266,291,317,345,373,403,433,464,497,530,564,599,635,672,710,748,
//788,828,868,910,952,995,1038,1082,1127,1172,1218,1264,1310,1358,1405,1453,1501,
//1550,1599,1648,1697,1747,1797,1847,1897,1947,1997 };
//
//uint16_t sine_wave_noise[256] = {3583,1800,770,4003,1699,3247,3858,2395,2408,4081,1242,331,3709,
//779,1231,1789,2691,938,696,239,112,3676,2694,1442,2769,1663,1665,2981,1475,2620,21,3657,1794,685,
//1372,651,3857,3558,2608,708,2057,323,1593,3475,3886,3630,294,2817,593,2614,2260,31,2703,3135,4034,
//586,1959,1588,1086,2869,669,2237,3338,2844,3300,2851,3934,1303,2026,1983,593,2404,3066,133,3593,
//926,1222,992,1440,1625,2347,2970,3084,4010,2822,194,1577,308,1845,1157,3030,3406,1037,915,1416,
//1892,2659,1471,3219,3394,2154,18,3896,889,1654,2147,523,242,1128,33,982,1055,1066,2814,3886,561,819,
//428,1425,4036,3808,989,1320,4000,542,3682,38,3172,1015,509,3567,1727,3874,3056,519,1151,907,3880,2059,
//1397,3790,3214,1790,1262,3115,1186,1420,1689,2968,791,833,1905,530,3862,3276,1476,1519,2406,3365,
//467,2832,721,829,699,258,94,2734,980,1047,4069,3545,1339,1030,2632,3209,2363,2024,294,2065,3972,
//2964,1545,2667,3106,2283,739,3580,2903,932,3864,1532,2338,2856,687,1965,1566,2056,327,3393,578,
//4086,3823,3144,1196,3575,2595,2698,657,2197,2270,2667,974,1675,2184,3559,2837,3524,3585,1145,
//1422,1651,3629,600,2545,3031,686,2261,1512,787,2660,1135,1240,2286,4019,2136,2724,2655,816,1492,1715,
//3064,1892,2834,1496,1335,1336,2593,2496,577,3427,1270,534,2968,3134,821 };
//
//uint16_t periode_PWM=400;
//float pulse_width;
//float pulse_width_noise;
//int nb_harmoniques;
//int k;
//float frequencies[5]={261.6,440,587.4,784,1318.8};
//uint32_t freq_timer7=50000000;
//uint16_t nbr_points =256;
//float period_overflow;
//float a;
//int harmonics[5]={1,2,3,4,5};

/*
Formule pour trouver frequence: 
f_sin = f_timer7/(nbre_point*period_overflow_timer7)
= 100*10^6/(256* period_overflow_timer7)
*/ 
/*timer 4 generate signal on pin D15*/
/*timer 7 generate overflow/change duty cycle of PWM */
/*timer 2 generate noise or harmonique of signal on pin D9 */

/* USER CODE END PV */

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	int i;
//	if(htim->Instance==TIM7)
//	{
//		//pulse_width=((float)(sine_wave_array[k])/(float)(4096))*periode_PWM;
//		//pulse_width=((float)(sine_wave_array[k]+sine_wave_array[(2*k)%256])/(float)(2*4096))*periode_PWM;
//		pulse_width_noise=(float)(sine_wave_noise[k]);
//		pulse_width=((float)(sine_wave_array[k]));
//		for (i=1;i<nb_harmoniques;i++){
//			pulse_width+=((float)(sine_wave_array[(harmonics[i]*k)%256]));
//		}
//		pulse_width=(pulse_width/(float)((nb_harmoniques)*4096))*periode_PWM;
//
//		k++;
//		if (k==256){
//			k=0;
//		}
//		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_3, pulse_width);
//		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse_width_noise);
//	}
//	else if (htim->Instance==TIM6)
//	{
//		TouchScreen_Polling();
//	}
//}
//
//
//void Generate_signal(float freq,int nb)
//{
//	//uint8_t nbr_freq=sizeof(frequencies)/sizeof(frequencies[0]);
//	//uint8_t i=0;
//	period_overflow=(freq_timer7+freq_timer7)/(freq*nbr_points);
//	nb_harmoniques=nb;
//	__HAL_TIM_SET_AUTORELOAD(&htim4,periode_PWM);
//	  __HAL_TIM_SET_AUTORELOAD(&htim2,periode_PWM);
//	__HAL_TIM_SET_AUTORELOAD(&htim7,period_overflow);
//	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
//	HAL_TIM_Base_Start_IT(&htim7);
//	//HAL_Delay(1000);
//	/*for (i=0;i<nbr_freq;i++)
//	{
//		period_overflow=(freq_timer7+freq_timer7)/(frequencies[i]*nbr_points);
//		__HAL_TIM_SET_AUTORELOAD(&htim7,period_overflow);
//		HAL_Delay(1000);
//	}*/
//}
//void Stop_signal()
//{
//	  HAL_TIM_PWM_Stop(&htim4,TIM_CHANNEL_3);
//}
//void Generate_noise()
//{
//	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
//}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
/*int main(void)*/
//{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
 // HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
 // SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /*MX_GPIO_Init();
  MX_TIM4_Init();
  MX_TIM7_Init();
  MX_GFXSIMULATOR_Init();
  MX_TIM2_Init();*/
  /* USER CODE BEGIN 2 */
	/*__HAL_TIM_SET_AUTORELOAD(&htim4,periode_PWM);
	__HAL_TIM_SET_AUTORELOAD(&htim2,periode_PWM);*/
	//HAL_TIM_Base_Start_IT(&htim7);

	/*Generate_signal(440,3);
	Generate_noise();
	HAL_TIM_Base_Start_IT(&htim7);*/
	
	//__HAL_TIM_SET_AUTORELOAD(&htim7,888);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 // while (1)
  //{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  //}
  /* USER CODE END 3 */
//}

/**
  * @brief System Clock Configuration
  * @retval None
  */

