/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include "stm32f4xx_hal.h"
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LCD_D7_Pin GPIO_PIN_13
#define LCD_D7_GPIO_Port GPIOC
#define LCD_CD_Pin GPIO_PIN_14
#define LCD_CD_GPIO_Port GPIOC
#define LCD_RW_Pin GPIO_PIN_15
#define LCD_RW_GPIO_Port GPIOC
#define ADC_TEMP_Pin GPIO_PIN_1
#define ADC_TEMP_GPIO_Port GPIOC
#define ADC_CURRENT_Pin GPIO_PIN_2
#define ADC_CURRENT_GPIO_Port GPIOC
#define ADC_VOLTAGE_Pin GPIO_PIN_3
#define ADC_VOLTAGE_GPIO_Port GPIOC
#define ENCODER1_A_Pin GPIO_PIN_0
#define ENCODER1_A_GPIO_Port GPIOA
#define ENCODER1_B_Pin GPIO_PIN_1
#define ENCODER1_B_GPIO_Port GPIOA
#define ENCODER1_BTN_Pin GPIO_PIN_3
#define ENCODER1_BTN_GPIO_Port GPIOA
#define ENCODER1_BTN_EXTI_IRQn EXTI3_IRQn
#define DAC_VOLTAGE_Pin GPIO_PIN_4
#define DAC_VOLTAGE_GPIO_Port GPIOA
#define DAC_CURRENT_Pin GPIO_PIN_5
#define DAC_CURRENT_GPIO_Port GPIOA
#define ENCODER2_A_Pin GPIO_PIN_6
#define ENCODER2_A_GPIO_Port GPIOA
#define ENCODER2_B_Pin GPIO_PIN_7
#define ENCODER2_B_GPIO_Port GPIOA
#define ENCODER2_BTN_Pin GPIO_PIN_4
#define ENCODER2_BTN_GPIO_Port GPIOC
#define ENCODER2_BTN_EXTI_IRQn EXTI4_IRQn
#define LED_FUSE_Pin GPIO_PIN_5
#define LED_FUSE_GPIO_Port GPIOC
#define LED_OUTPUT_Pin GPIO_PIN_0
#define LED_OUTPUT_GPIO_Port GPIOB
#define OUTPUT_FET_Pin GPIO_PIN_1
#define OUTPUT_FET_GPIO_Port GPIOB
#define BTN_FUSE_Pin GPIO_PIN_2
#define BTN_FUSE_GPIO_Port GPIOB
#define BTN_FUSE_EXTI_IRQn EXTI2_IRQn
#define BTN_OUTPUT_Pin GPIO_PIN_10
#define BTN_OUTPUT_GPIO_Port GPIOB
#define BTN_OUTPUT_EXTI_IRQn EXTI15_10_IRQn
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_DM_Pin GPIO_PIN_11
#define USB_DM_GPIO_Port GPIOA
#define USB_DP_Pin GPIO_PIN_12
#define USB_DP_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_15
#define LCD_RESET_GPIO_Port GPIOA
#define LCD_EN1_Pin GPIO_PIN_11
#define LCD_EN1_GPIO_Port GPIOC
#define LCD_EN2_Pin GPIO_PIN_2
#define LCD_EN2_GPIO_Port GPIOD
#define LCD_D0_Pin GPIO_PIN_3
#define LCD_D0_GPIO_Port GPIOB
#define LCD_D1_Pin GPIO_PIN_4
#define LCD_D1_GPIO_Port GPIOB
#define LCD_D2_Pin GPIO_PIN_5
#define LCD_D2_GPIO_Port GPIOB
#define LCD_D3_Pin GPIO_PIN_6
#define LCD_D3_GPIO_Port GPIOB
#define LCD_D4_Pin GPIO_PIN_7
#define LCD_D4_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_8
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_9
#define LCD_D6_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
