#include "peripherals.h"
#include "tim.h"

struct Callbacks {
	EncoderTurnedCallback_fptr encoderATurnedCallbacks[8];
	EncoderTurnedCallback_fptr encoderBTurnedCallbacks[8];
	ButtonCallback_fptr encoderAButtonCallbacks[8];
	ButtonCallback_fptr encoderBButtonCallbacks[8];
	ButtonCallback_fptr fuseCallbacks[8];
	ButtonCallback_fptr outputCallbacks[8];
	USBReceivedCallback_fptr usbReceivedCallbacks[8];
} callbacks;

void addEncoderATurnedCallback(EncoderTurnedCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.encoderATurnedCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addEncoderBTurnedCallback(EncoderTurnedCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.encoderBTurnedCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addEncoderAButtonCallback(ButtonCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.encoderAButtonCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addEncoderBButtonCallback(ButtonCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.encoderBButtonCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addFuseButtonCallback(ButtonCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.fuseCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addOutputButtonCallback(ButtonCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.outputCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void addUSBReceivedCallback(USBReceivedCallback_fptr fptr) {
	static uint8_t callbackPtr = 0;
	
	callbacks.usbReceivedCallbacks[callbackPtr++] = fptr;
	if(callbackPtr > 8) callbackPtr = 0;
}

void initCallbacks(void)
{
	uint8_t callback;
	for(callback = 0; callback < 8; callback++){
		callbacks.encoderAButtonCallbacks[callback] = NULL;
		callbacks.encoderATurnedCallbacks[callback] = NULL;
		callbacks.encoderBTurnedCallbacks[callback] = NULL;
		callbacks.encoderAButtonCallbacks[callback] = NULL;
		callbacks.encoderBButtonCallbacks[callback] = NULL;
		callbacks.fuseCallbacks[callback] = NULL;
		callbacks.outputCallbacks[callback] = NULL;
		callbacks.usbReceivedCallbacks[callback] = NULL;
	}
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start(&htim3);
	HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_1|TIM_CHANNEL_2);
	TIM2 -> CNT = 100;
	TIM3 -> CNT = 100;
}

void handleEncoderCallbacks(void) {
	if(TIM2->CNT != 100) {
		uint8_t callback;
		for(callback = 0; callback < 8; callback++)
			if(callbacks.encoderATurnedCallbacks[callback] != NULL)
				callbacks.encoderATurnedCallbacks[callback]((TIM2->CNT-100));
			
		TIM2->CNT = 100;
	}
	
	if(TIM3->CNT != 100) {
		uint8_t callback;
		for(callback = 0; callback < 8; callback++)
			if(callbacks.encoderBTurnedCallbacks[callback] != NULL)
				callbacks.encoderBTurnedCallbacks[callback]((TIM3->CNT-100));
			
		TIM3->CNT = 100;
	}
}

/**
* @brief This function handles EXTI line2 interrupt.
*/
void EXTI2_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN EXTI2_IRQn 0 */
	for(callback = 0; callback < 8; callback++)
		if(callbacks.fuseCallbacks[callback] != NULL)
      callbacks.fuseCallbacks[callback]();
		
  /* USER CODE END EXTI2_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
  /* USER CODE BEGIN EXTI2_IRQn 1 */
	
  /* USER CODE END EXTI2_IRQn 1 */
}

/**
* @brief This function handles EXTI line3 interrupt.
*/
void EXTI3_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN EXTI3_IRQn 0 */
	
	for(callback = 0; callback < 8; callback++)
		if(callbacks.encoderAButtonCallbacks[callback] != NULL)
      callbacks.encoderAButtonCallbacks[callback]();
  /* USER CODE END EXTI3_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
  /* USER CODE BEGIN EXTI3_IRQn 1 */

  /* USER CODE END EXTI3_IRQn 1 */
}

/**
* @brief This function handles EXTI line4 interrupt.
*/
void EXTI4_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN EXTI4_IRQn 0 */
	for(callback = 0; callback < 8; callback++)
		if(callbacks.encoderBButtonCallbacks[callback] != NULL)
      callbacks.encoderBButtonCallbacks[callback]();
  /* USER CODE END EXTI4_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_IRQn 1 */

  /* USER CODE END EXTI4_IRQn 1 */
}

/**
* @brief This function handles TIM2 global interrupt.
*/
void TIM2_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN TIM2_IRQn 0 */
	for(callback = 0; callback < 8; callback++)
		if(callbacks.encoderATurnedCallbacks[callback] != NULL){
      callbacks.encoderATurnedCallbacks[callback](__HAL_TIM_GetCounter(&htim2));
			__HAL_TIM_SetCounter(&htim2, 100);
	}
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
* @brief This function handles TIM3 global interrupt.
*/
void TIM3_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN TIM3_IRQn 0 */
	for(callback = 0; callback < 8; callback++)
		if(callbacks.encoderBTurnedCallbacks[callback] != NULL){
      callbacks.encoderBTurnedCallbacks[callback](__HAL_TIM_GetCounter(&htim3));
			__HAL_TIM_SetCounter(&htim3, 100);
		}
  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
* @brief This function handles EXTI line[15:10] interrupts.
*/
void EXTI15_10_IRQHandler(void)
{
	uint8_t callback;
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
	for(callback = 0; callback < 8; callback++)
		if(callbacks.outputCallbacks[callback] != NULL)
      callbacks.outputCallbacks[callback]();
  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}
