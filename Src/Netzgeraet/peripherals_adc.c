#include "peripherals.h"

#define UIN_FACTOR (UREF * SPANNUNGSTEILER / 4096.0F)
#define IIN_FACTOR ((UREF / (4.096F * 2.2F)))
#define TEMP_FACTOR (UREF / 40.96F)

uint32_t adcValue[3];

void initADC(ADC_HandleTypeDef *adcHandler)
{
	HAL_ADC_Start_DMA(adcHandler, adcValue, 3);
}

float getADCValue(ADC_Data data)
{
	return (adcValue[(uint8_t) data] * (data == TEMP ? TEMP_FACTOR : 1) * (data == I_IST ? IIN_FACTOR : 1) * (data == U_IST ? UIN_FACTOR : 1));
}
