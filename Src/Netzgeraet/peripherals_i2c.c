#include "peripherals.h"

#include "i2c.h"

void setBrightness(uint8_t percent) {
	uint8_t data[] = { (uint8_t)((((float)0xFF) / 100) * ((percent * 0.6) + 40)) };
    HAL_I2C_Mem_Write(&hi2c3, (uint16_t) (0x50), 0x11, I2C_MEMADD_SIZE_8BIT, data, 1, 1000);
}

void setContrast(uint8_t percent) {
	uint8_t data[] = { (uint8_t)(0xFF - ( (((float)0xFF) / 100) * ((percent * 0.15) + 85)) ) };
	
	HAL_I2C_Mem_Write(&hi2c3, (uint16_t) (0x50), 0x12, I2C_MEMADD_SIZE_8BIT, data, 1, 1000);
}
