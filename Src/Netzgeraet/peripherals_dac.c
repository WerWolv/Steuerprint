#include "peripherals.h"

#define UOUT_FACTOR (4095.0F / (SPANNUNGSTEILER * UREF))
#define IOUT_FACTOR ((2.2F * 4096.0F / UREF) / 1000.0F)

uint32_t dacValue[2];

void initDAC(DAC_HandleTypeDef *dacHandler, TIM_HandleTypeDef *timerHandler)
{
	HAL_TIM_Base_Start(timerHandler);
	HAL_DAC_Start(dacHandler, DAC_CHANNEL_1);  
	HAL_DAC_Start(dacHandler, DAC_CHANNEL_2);  
	HAL_DAC_Start_DMA(dacHandler, DAC_CHANNEL_1, &dacValue[0], 1, DAC_ALIGN_12B_R);
	HAL_DAC_Start_DMA(dacHandler, DAC_CHANNEL_2, &dacValue[1], 1, DAC_ALIGN_12B_R);
}

void setDACValue(DAC_Data data, float value)
{
	dacValue[data] = (uint32_t)(value * (data == U_SOLL ? (UOUT_FACTOR) : 1) * (data == I_SOLL ? IOUT_FACTOR : 1));
}
