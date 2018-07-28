#include "stm32f4xx_hal.h"
#include "peripherals.h"

TIM_HandleTypeDef *encHandleA, *encHandleB;

void initEncoder(TIM_HandleTypeDef *timHandleA, TIM_HandleTypeDef *timHandleB) {
	HAL_TIM_Base_Start(timHandleA);
	HAL_TIM_Base_Start(timHandleB);
	HAL_TIM_Encoder_Start(timHandleA, TIM_CHANNEL_1|TIM_CHANNEL_2);
	HAL_TIM_Encoder_Start(timHandleB, TIM_CHANNEL_1|TIM_CHANNEL_2);
	
	encHandleA = timHandleA;
	encHandleB = timHandleB;

	timHandleA->Instance->CNT = 100;
	timHandleB->Instance->CNT = 100;
}

EncoderDir getEncoderTurnDir(Encoder encoder) {
	int16_t buffer = (encoder == ENCODER_A ? encHandleA->Instance->CNT : encHandleB->Instance->CNT) - 100;
	
	if(encoder == ENCODER_A)
		encHandleA->Instance->CNT = 100;
	else
		encHandleB->Instance->CNT = 100;
	
	return buffer > 0 ? ENCODER_RIGHT : buffer < 0 ? ENCODER_LEFT : 0;
}
