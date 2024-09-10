/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
	typedef enum{false, true} bool;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void display7SEG ( int counter);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  int counter = 499,  counter_2 = 299;
  bool green_state = 1, yellow_state = 1; //initial state leds of ways 0 and 4
  //initial state green, yellow led turn off
  bool red_state = 0; //for noise
  bool anot = 0;
  //turn off led yellow and led green of way 0
  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

  //turn off led yellow and led green of way 4
  HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_SET);

  //turn off led yellow ways 2,3
  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_YELLOW_3_GPIO_Port, LED_YELLOW_3_Pin, GPIO_PIN_SET);

  //turn off led red ways 2,3
  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_SET);

  HAL_GPIO_WritePin(Anot_Common_GPIO_Port, Anot_Common_Pin, GPIO_PIN_SET);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(counter >499) //for noise
		  counter = 499;

	  if(counter_2 > 499) //for noise
		  counter = 499;

	  if(green_state && yellow_state && red_state)//for noise make all of leds turn off
		  red_state = 0;

	  switch(yellow_state)
	  {
	  	  case 0: // 0 meaning this led is turning off
			  if(counter > 0) //for noise
			  {
				  //turn on led red ways 2,3
				  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);

				  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, GPIO_PIN_RESET);
			  }

			  if(counter < 1)
			  {
				  //turn off led yellow
				  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, GPIO_PIN_SET);
				  yellow_state = 1;

				  //set counter for red
				  counter = 499;

				  //turn on led red
				  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
				  red_state = 0;

				  //turn off led red ways 2,3
				  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_SET);

				  //turn on led green ways 2,3
				  counter_2 = 299;
				  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
			  }
	  		  break;

	  	  default: //if turn off, switch to another ways
	  		  break;
	  }

	  switch(green_state)
	  {
	  	  case 0:

	  		  if(counter > 0) //for noise
		  {
	  			  //turn on led red ways 2,3
				  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);

			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
		  }

	  		  if(counter < 1)
		  {
			  //turn off led green
			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_SET);
			  green_state = 1;

			  //set counter for yellow
			  counter = 199;

			  //turn on led yellow
			  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(LED_YELLOW_4_GPIO_Port, LED_YELLOW_4_Pin, GPIO_PIN_RESET);
			  yellow_state = 0;
		  }
	  		  break;

	  	  default:
	  		  break;
	  }

	  switch(red_state)
	  {
	  	  case 0:
	  		  if(counter > 199)
	  		  {
	  			  //turn on led green ways 2,3
				  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_RESET);
	  		  }

	  		  if(counter < 200)
	  		  {
	  			  //turn off led green ways 2,3
				  HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
				  HAL_GPIO_WritePin(LED_GREEN_3_GPIO_Port, LED_GREEN_3_Pin, GPIO_PIN_SET);

	  			  //turn on led yellow ways 2,3
				  counter_2 = 199;
				  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(LED_YELLOW_3_GPIO_Port, LED_YELLOW_3_Pin, GPIO_PIN_RESET);
	  		  }


	  		  if(counter > 0) //for noise if it make turn off red led
		  {
			  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_RESET);
		  }

	  		  if(counter < 1)
		  {
			  //turn off led red
			  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(LED_RED_4_GPIO_Port, LED_RED_4_Pin, GPIO_PIN_SET);
			  red_state = 1;

			  //set counter for green
			  counter = 299;

			  //turn on led green
			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(LED_GREEN_4_GPIO_Port, LED_GREEN_4_Pin, GPIO_PIN_RESET);
			  green_state = 0;

			  //turn off led yellow ways 2,3
			  HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
			  HAL_GPIO_WritePin(LED_YELLOW_3_GPIO_Port, LED_YELLOW_3_Pin, GPIO_PIN_SET);

			  //turn on led red ways 2,3
			  HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(LED_RED_3_GPIO_Port, LED_RED_3_Pin, GPIO_PIN_RESET);
			  counter_2 = 499;

		  }
	  		  break;

	  	  default:
	  		  break;
	  }


/* THESE FOR INIT COUNTER = 0 AND COUNTER++ AND THEY'S USELESS AGAINST NOISE and not use red_state
	  switch(counter){
	  	  case 2:
	  		  if(yellow_state < 1) //equal 0 LED on
	  		  {
	  			  	 //turn off yellow led
	  			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
	  			yellow_state = 1;
	  				//turn on green led
	  			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
	  			green_state = 0;
	  			//reset counter
	  			counter = 0;
	  		  }
	  		  break;
	  	  case 3:
	  		  if(green_state < 1) //equal 0 LED ON
	  		  {
	  			  //Turn off green led
	  			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
	  			green_state = 1;
	  				//Turn on red led
	  			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	  			//red_state = 1;
	  			//reset counter
	  			counter = 0;
	  		  }
	  		  break;
	  	  case 5:
	  		  //turn off red led
	  		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	  		//red_state = 0;
	  		//turn on yellow led
	  		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			yellow_state = 0;
			//set counter = 0
	  		counter = 0;
	  		  break;
	  	  default:
	  		  //std::throw "change value by noise";
	  		  break;
	  }
*/
	  switch(anot)
	  {
	  	  case 0:
	  		  display7SEG(counter_2/100);
	  		  break;
	  	  default:
	  		  display7SEG(counter/100);
	  		  break;
	  }
	  anot = !anot;
	  HAL_GPIO_TogglePin(Anot_Common_GPIO_Port, Anot_Common_Pin);
	  counter_2--;
	  counter--;
	  HAL_Delay(10);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin|A_7_SEG_Pin|B_7_SEG_Pin
                          |C_7_SEG_Pin|D_7_SEG_Pin|E_7_SEG_Pin|F_7_SEG_Pin
                          |G_7_SEG_Pin|Anot_Common_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_RED_3_Pin|LED_YELLOW_3_Pin|LED_GREEN_3_Pin|LED_RED_4_Pin
                          |LED_YELLOW_4_Pin|LED_GREEN_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_2_Pin LED_YELLOW_2_Pin LED_GREEN_2_Pin LED_RED_Pin
                           LED_YELLOW_Pin LED_GREEN_Pin A_7_SEG_Pin B_7_SEG_Pin
                           C_7_SEG_Pin D_7_SEG_Pin E_7_SEG_Pin F_7_SEG_Pin
                           G_7_SEG_Pin Anot_Common_Pin */
  GPIO_InitStruct.Pin = LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin|A_7_SEG_Pin|B_7_SEG_Pin
                          |C_7_SEG_Pin|D_7_SEG_Pin|E_7_SEG_Pin|F_7_SEG_Pin
                          |G_7_SEG_Pin|Anot_Common_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_RED_3_Pin LED_YELLOW_3_Pin LED_GREEN_3_Pin LED_RED_4_Pin
                           LED_YELLOW_4_Pin LED_GREEN_4_Pin */
  GPIO_InitStruct.Pin = LED_RED_3_Pin|LED_YELLOW_3_Pin|LED_GREEN_3_Pin|LED_RED_4_Pin
                          |LED_YELLOW_4_Pin|LED_GREEN_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
	void display7SEG ( int counter)
	{
		switch(counter)
		{
			case 0:
				HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
				break;
			case 1:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
				break;
			case 2:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			case 3:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			case 4:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			case 5:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			case 6:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			case 7:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_SET);
				break;
			case 8:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
			default:
			HAL_GPIO_WritePin(A_7_SEG_GPIO_Port, A_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_7_SEG_GPIO_Port, B_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_7_SEG_GPIO_Port, C_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_7_SEG_GPIO_Port, D_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_7_SEG_GPIO_Port, E_7_SEG_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_7_SEG_GPIO_Port, F_7_SEG_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_7_SEG_GPIO_Port, G_7_SEG_Pin, GPIO_PIN_RESET);
				break;
		}
	}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
