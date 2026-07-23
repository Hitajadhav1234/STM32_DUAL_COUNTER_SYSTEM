/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim14;

/* USER CODE BEGIN PV */
int16_t TimRef;
int state=1;
int KeyReadFlg=0;
int sw1_status;
int sw2_status;
int sw1_lock=0;
int sw1_lk=0;
int sw2_lk=0;
int sw2_lock=0;
int blink;
int8_t j=0;
int8_t data;
int8_t LedData;
uint8_t digit[10] =
{
    0b01111110, // 0
    0b00110000, // 1
    0b01101101, // 2
    0b01111001, // 3
    0b00110011, // 4
    0b01011011, // 5
    0b01011111, // 6
    0b01110000, // 7
    0b01111111, // 8
	0b01111011
};
uint8_t SetValue = 0;
uint8_t SetMode =0 ;
uint8_t number = 0;
int16_t Tim=0;
uint8_t ones;
uint8_t tens;
uint32_t SetModeTimer = 0;
uint32_t ResetModeTimer = 0;
uint8_t BlinkState = 1;
uint32_t BlinkTimer = 0;
uint32_t SW1PressTimer = 0;
uint32_t SW2PressTimer = 0;

uint8_t SW1LongPress = 0;
uint8_t SW2LongPress = 0;
uint32_t SW1RepeatTimer = 0;
uint32_t SW2RepeatTimer = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM14_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
//void keyread(void);
//void ledblink(void);
//void keyaction(void);
//void display(void);
//void store(void);
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
  MX_TIM14_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  // DATA = 1
//  {
//  while(1)
//	  HAL_Delay(500);
//	  HAL_GPIO_TogglePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin);
//	  HAL_GPIO_TogglePin(CLOCK_GPIO_Port, CLOCK_Pin);
//	  HAL_GPIO_TogglePin(DATA_IN_GPIO_Port, DATA_IN_Pin);
//  }
//  HAL_Delay(1000);
//  HAL_GPIO_WritePin(uC1_GPIO_Port, uC1_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(uC2_GPIO_Port, uC2_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_RESET);
//
//  HAL_GPIO_WritePin(CLOCK_GPIO_Port, CLOCK_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin, GPIO_PIN_SET);
//
//  // 8 clock pulses
//  for(int i=0; i<8; i++)
//  {
//	  HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin, GPIO_PIN_SET);
//	  HAL_Delay(5);
//	  HAL_GPIO_WritePin(CLOCK_GPIO_Port, CLOCK_Pin, GPIO_PIN_SET);
//	  HAL_Delay(5);
//	  HAL_GPIO_WritePin(CLOCK_GPIO_Port, CLOCK_Pin, GPIO_PIN_RESET);
//  }
//  HAL_GPIO_WritePin(CLOCK_GPIO_Port, CLOCK_Pin, GPIO_PIN_SET);
//  HAL_Delay(20);
//  HAL_GPIO_WritePin(CLOCK_GPIO_Port, CLOCK_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin, GPIO_PIN_RESET);
//  HAL_GPIO_WritePin(uC1_GPIO_Port, uC1_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(uC2_GPIO_Port, uC2_Pin, GPIO_PIN_SET);
//  HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_SET);
//HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);
//HAL_I2C_Mem_Write(&hi2c1, 0XA0, 0, 1,digit, sizeof(digit), 1000);
//HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);
//HAL_I2C_Mem_Read(&hi2c1, 0XA1, 0, 1, empty , sizeof(empty), 1000);

//  while(1)
//  {
//	  if(TimRef ==1)
//	  {
//		  TimRef=0;
//		  Tim++;
//		  switch (Tim) {
//			case 1:
//				LedData = 0b00000000;
//				break;
//			case 2:
//				LedData = 0b00010000;
//				break;
////			case 3:
////				LedData = 0b00000000;
//				break;
//			default:
//				if(Tim >=2)
//				{
//					Tim=0;
//				}
//				break;
//		}
//		HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_SET);
//		  for(int i=0;i<8;i++)
//		  {
//			  if(data & (1<<i))
//				  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
//			  else
//				  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//			  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//			  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//		  }
//
//		  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);
//		  HAL_Delay(1000);
//
//	  }
//
//  }

  /* USER CODE END 2 */


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	    data = digit[j];
//
//	    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);
//
//	    for(int i=0; i<8; i++)
//	    {
//	        if(data & (1<<i))
//	        {
//	            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
//	        }
//	        else
//	        {
//	            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//	        }
//
//	        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//
//	        HAL_Delay(5);
//
//	        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//
//	        HAL_Delay(5);
//	    }
//
//	    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);
//
//	    HAL_Delay(1000);
//
//	    j++;
//
//	    if(j > 9)
//	    {
//	        j = 0;
//	    }
//	  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);
//	  HAL_I2C_Mem_Read(&hi2c1, 0XA0, 0x00,I2C_MEMADD_SIZE_8BIT,&number,1,1000);
//	  if(TimRef)
//	  {
//		  TimRef =0;
//		  Tim++;
//		  switch(state)
//		  {
//		      case 1:
//
//		          keyread();
//
//		          if(KeyReadFlg == 1)
//		          {
//
//		              keyaction();
//		              KeyReadFlg = 0;
//		              store();
//		          }
//
//		          break;
//		default:
//				if(Tim>=4)
//				{
//					Tim = 0;
//				}
//				break;
//		}
//		  display();
//	  }
      for(int refresh=0; refresh<100; refresh++)
	      {
    	  //state selection
			  if(state == 1)
			  {
				  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)==GPIO_PIN_RESET &&
					 HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)==GPIO_PIN_RESET)
				  {
					  if(SetModeTimer == 0)
					  {
						  SetModeTimer = HAL_GetTick();
					  }

					  if((HAL_GetTick() - SetModeTimer) >= 2000)
					  {
						  state = 2;

						  HAL_GPIO_WritePin(uC3_GPIO_Port,uC3_Pin,	GPIO_PIN_SET);
						  blink =1;
						  HAL_GPIO_WritePin(FEEWP_GPIO_Port,	FEEWP_Pin,GPIO_PIN_SET);

						  HAL_I2C_Mem_Read(&hi2c1, 0xA0, 0x01, I2C_MEMADD_SIZE_8BIT,  &SetValue,  1,1000);

						  ResetModeTimer = HAL_GetTick();
					  }
				  }
				  else
				  {
					  SetModeTimer = 0;
				  }
			  }
			  if(state == 2)
			  {
			      if((HAL_GetTick() - BlinkTimer) >= 500)
			      {
			          BlinkTimer = HAL_GetTick();
			          if(BlinkState==0)
			          {
			        	  BlinkState=1;
			          }
			          else
			          {
			        	  BlinkState=0;
			          }
			      }
			  }
			  else
			  {
			      BlinkState = 1;
			  }
	    	  if(state==1)
	    	  {
				  //NORMAL MODE
				  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);
				  HAL_I2C_Mem_Read(&hi2c1, 0XA0, 0x00,I2C_MEMADD_SIZE_8BIT,&number,1,1000);
				  tens = number / 10;
				  ones = number % 10;

				  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)==GPIO_PIN_RESET)
				  {
					  if(sw1_lock==0)
					  {
						  number++;
						  if(number>99)
						  {
							  number=0;
						  }
						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);
						  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x00,I2C_MEMADD_SIZE_8BIT,&number,1,1000);
						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);

						  tens = number / 10;
						  ones = number % 10;
						  sw1_lock=1;
					   }
				  }
				  else
				  {
					  sw1_lock =0;
				  }
				  if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)==GPIO_PIN_RESET)
				  {
					  if(sw2_lock==0)
					  {
						  if(number==0)
						  {
							  number=99;
						  }
						  else
						  {
							  number--;
						  }

						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);

						  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x00,I2C_MEMADD_SIZE_8BIT, &number, 1,1000);
						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);

						  tens = number / 10;
						  ones = number % 10;
						  sw2_lock =1;
					  }
				  }
				  else
								  {
									  sw2_lock =0;
								  }

//				  //left
//
//				  HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_RESET);
//				  HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_SET);
//
//				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);
//
//				  data = digit[tens];
//
//				  for(int i=0;i<8;i++)
//				  {
//					  if(data & (1<<i))
//						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
//					  else
//						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//				  }
//
//				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);
//
//				  HAL_Delay(5);
//
//				  //right
//
//				  HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_RESET);
//				  HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_SET);
//
//				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);
//
//				  data = digit[ones];
//
//				  for(int i=0;i<8;i++)
//				  {
//					  if(data & (1<<i))
//						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin,GPIO_PIN_SET);
//					  else
//						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//
//					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//				  }
//
//				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin, GPIO_PIN_RESET);
//				  HAL_Delay(5);
	     	}


	    	  else if(state == 2)
	    	  {
	    	      tens = SetValue / 10;
	    	      ones = SetValue % 10;

					  // Increment
	    	      if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)==GPIO_PIN_RESET &&HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin)==GPIO_PIN_RESET)
	    	      {

	    	      }
	    	      else
	    	      {
					  if(HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin)==GPIO_PIN_RESET)
					  {
						  if(sw1_lk == 0)
						  {
							  sw1_lk = 1;
							  SW1PressTimer = HAL_GetTick();
							  SW1RepeatTimer = HAL_GetTick();
						  }
						  if((HAL_GetTick() - SW1PressTimer) >= 2000)
							  {
							  if((HAL_GetTick() - SW1RepeatTimer) >= 2000)
								  {
									  SW1RepeatTimer = HAL_GetTick();

									  SetValue += 10;

									  if(SetValue > 99)
									  {
										  SetValue %= 100;
									  }

									  HAL_GPIO_WritePin(FEEWP_GPIO_Port,FEEWP_Pin,GPIO_PIN_RESET);

									  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT, &SetValue,1,1000);

									  HAL_GPIO_WritePin(FEEWP_GPIO_Port,FEEWP_Pin,GPIO_PIN_SET);

									  ResetModeTimer = HAL_GetTick();
								  }
							  }
					  }
					  else
					  {
						  if(sw1_lk == 1)
						  {
							  if((HAL_GetTick() - SW1PressTimer) < 2000)
							  {
								  SetValue++;

								  if(SetValue > 99)
									  SetValue = 0;

								  HAL_GPIO_WritePin(FEEWP_GPIO_Port,FEEWP_Pin,GPIO_PIN_RESET);

								  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT,&SetValue,1,1000);

								  HAL_GPIO_WritePin(FEEWP_GPIO_Port,FEEWP_Pin,GPIO_PIN_SET);

								  ResetModeTimer = HAL_GetTick();
							  }
						  }

						  sw1_lk = 0;
					  }

					  // Decrement
					  if(HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin) == GPIO_PIN_RESET)
					  {
						  if(sw2_lk == 0)
						  {
							  sw2_lk = 1;
							  SW2PressTimer = HAL_GetTick();
							  SW2RepeatTimer = HAL_GetTick();
						  }

						  // Long Press (-10)
						  if((HAL_GetTick() - SW2PressTimer) >= 2000)
						  {
							  if((HAL_GetTick() - SW2RepeatTimer) >= 2000)
								  {
									  SW2RepeatTimer = HAL_GetTick();

									  if(SetValue < 10)
									  {
										  SetValue = 100 + SetValue - 10;
									  }
									  else
									  {
										  SetValue -= 10;
									  }


									  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);

									  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT,&SetValue,1,1000);

									  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);

									  ResetModeTimer = HAL_GetTick();
								  }
						  }
					  }
					  else
					  {
						  // Button Released
						  if(sw2_lk == 1)
						  {
							  // Short Press (-1)
							  if((HAL_GetTick() - SW2PressTimer) < 2000)
							  {
								  if(SetValue == 0)
								  {
									  SetValue = 99;
								  }
								  else
								  {
									  SetValue--;
								  }

								  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);

								  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT,&SetValue, 1, 1000);

								  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);

								  ResetModeTimer = HAL_GetTick();
							  }
						  }

						  // Reset locks after release
						  sw2_lk = 0;
					  }
	    	      }
	    	      // Exit after 10 sec

	    	      if((HAL_GetTick() - ResetModeTimer) >= 10000)
	    	      {
	    	          state = 1;
	    	          blink = 0;
	    	          HAL_GPIO_WritePin(uC3_GPIO_Port,uC3_Pin,GPIO_PIN_RESET);

	    	          SetModeTimer = 0;
	    	      }
	    	  }
	    	  	  	  	  	  //left

	    	  				  HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_RESET);
	    	  				  HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_SET);

	    	  				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);

	    	  				if(state == 2 && BlinkState == 0)
	    	  				{
	    	  				    data = 0x00;      // Blank
	    	  				}
	    	  				else
	    	  				{
	    	  				    data = digit[tens];
	    	  				}

	    	  				  for(int i=0;i<8;i++)
	    	  				  {
	    	  					  if(data & (1<<i))
	    	  						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
	    	  					  else
	    	  						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);

	    	  					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
	    	  					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
	    	  				  }

	    	  				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);

	    	  				  HAL_Delay(5);

	    	  				  //right

	    	  				  HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_RESET);
	    	  				  HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_SET);

	    	  				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);

	    	  				if(state == 2 && BlinkState == 0)
	    	  				{
	    	  				    data = 0x00;
	    	  				}
	    	  				else
	    	  				{
	    	  				    data = digit[ones];
	    	  				}

	    	  				  for(int i=0;i<8;i++)
	    	  				  {
	    	  					  if(data & (1<<i))
	    	  						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin,GPIO_PIN_SET);
	    	  					  else
	    	  						  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);

	    	  					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);

	    	  					  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
	    	  				  }

	    	  				  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin, GPIO_PIN_RESET);
	    	  				  HAL_Delay(5);


	    	  				if(state == 2)
	    	  				{
	    	  				    HAL_GPIO_WritePin(uC1_GPIO_Port, uC1_Pin, GPIO_PIN_RESET);
	    	  				    HAL_GPIO_WritePin(uC2_GPIO_Port, uC2_Pin, GPIO_PIN_RESET);

	    	  				    HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_SET);

	    	  				    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin, GPIO_PIN_SET);

	    	  				    data = 0b0100000;      // Only B ON

	    	  				    for(int i=0;i<8;i++)
	    	  				    {
	    	  				        if(data & (1<<i))
	    	  				            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
	    	  				        else
	    	  				            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);

	    	  				        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
	    	  				        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
	    	  				    }

	    	  				    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin, GPIO_PIN_RESET);

	    	  				    HAL_Delay(2);

	    	  				    HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_RESET);
	    	  				}
	      }
	  }

}
  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00503D58;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 15;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 1000;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */
  HAL_TIM_Base_Start_IT(&htim14);
  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, uC3_Pin|uC2_Pin|uC1_Pin|CLOCK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port, OUTPUT_EN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : FEEWP_Pin */
  GPIO_InitStruct.Pin = FEEWP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(FEEWP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SW2_Pin SW1_Pin */
  GPIO_InitStruct.Pin = SW2_Pin|SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : uC3_Pin uC2_Pin uC1_Pin */
  GPIO_InitStruct.Pin = uC3_Pin|uC2_Pin|uC1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : DATA_IN_Pin */
  GPIO_InitStruct.Pin = DATA_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DATA_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OUTPUT_EN_Pin CLOCK_Pin */
  GPIO_InitStruct.Pin = OUTPUT_EN_Pin|CLOCK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
//void ledblink(void)
//{
//	  if(blink==1)
//	  {
////		  Tim++;
////		  switch (Tim) {
////			case 1:
////				LedData = 0b00000000;
////				break;
////			case 2:
////				LedData = 0b00010000;
////				break;
//////			case 3:
//////				LedData = 0b00000000;
////				break;
////			default:
////				if(Tim >=2)
////				{
////					Tim=0;
////				}
////				break;
//		  LedData =0b00010000;
//		}
//	  else
//	  {
//		  LedData = 0b00000000;
//	  }
//		HAL_GPIO_WritePin(uC3_GPIO_Port, uC3_Pin, GPIO_PIN_SET);
//		  for(int i=0;i<8;i++)
//		  {
//			  if(LedData & (1<<i))
//				  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
//			  else
//				  HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//			  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//			  HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//		  }
//
//		  HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);
// }

//void keyread(void)
//{
//	sw1_status=HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin);
//	sw2_status=HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin);
//	if((sw1_status   == 0) || (sw2_status   == 0))
//	{
//		KeyReadFlg=1;
//	}
//}
//
//void keyaction(void)
//{
//	//increment
//	if(sw1_status==GPIO_PIN_RESET)
//				  {
//					  if(sw1_lock==0)
//					  {
//						  number++;
//
//						  if(number>99)
//						  {
//							  number=0;
//						  }
//
//						  tens = number / 10;
//						  ones = number % 10;
//						  sw1_lock=1;
//					   }
//				  }
//				  else
//				  {
//					  sw1_lock =0;
//				  }
//
//
//	//decrement
//	if(sw2_status==GPIO_PIN_RESET)
//				  {
//					  if(sw2_lock==0)
//					  {
//						  if(number==0)
//						  {
//							  number=99;
//						  }
//						  else
//						  {
//							  number--;
//						  }
////
////						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);
////
////						  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT, &number, 1,1000);
////						  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);
//
//						  tens = number / 10;
//						  ones = number % 10;
//						  sw2_lock =1;
//					  }
//				  }
//				  else
//				  {
//				  		sw2_lock =0;
//				  }
//}
//
//void store(void)
//{
//	  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_RESET);
//	  HAL_I2C_Mem_Write(&hi2c1,0xA0,0x01,I2C_MEMADD_SIZE_8BIT, &number, 1,1000);
//	  HAL_GPIO_WritePin(FEEWP_GPIO_Port, FEEWP_Pin, GPIO_PIN_SET);
//}
//
//void display(void)
//{
//	  //left
//
//    HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_SET);
//
//    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);
//
//    data = digit[tens];
//
//    for(int i=0;i<8;i++)
//    {
//        if(data & (1<<i))
//            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_SET);
//        else
//            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//    }
//
//    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_RESET);
//
//    HAL_Delay(5);
//
//    //right
//
//    HAL_GPIO_WritePin(uC1_GPIO_Port,uC1_Pin,GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(uC2_GPIO_Port,uC2_Pin,GPIO_PIN_SET);
//
//    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin,GPIO_PIN_SET);
//
//    data = digit[ones];
//
//    for(int i=0;i<8;i++)
//    {
//        if(data & (1<<i))
//            HAL_GPIO_WritePin(DATA_IN_GPIO_Port, DATA_IN_Pin,GPIO_PIN_SET);
//        else
//            HAL_GPIO_WritePin(DATA_IN_GPIO_Port,DATA_IN_Pin,GPIO_PIN_RESET);
//
//        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_SET);
//
//        HAL_GPIO_WritePin(CLOCK_GPIO_Port,CLOCK_Pin,GPIO_PIN_RESET);
//    }
//
//    HAL_GPIO_WritePin(OUTPUT_EN_GPIO_Port,OUTPUT_EN_Pin, GPIO_PIN_RESET);
//    HAL_Delay(5);
//}

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
#ifdef USE_FULL_ASSERT
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
