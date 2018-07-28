#include "peripherals.h"
#include "spi.h"

uint8_t contrast, brightness;

void initSPI() {
	;
}

void setContrast(uint8_t contr) {
	uint8_t buffer[] = {0x00, contr};
	//HAL_SPI_Transmit(&hspi2, buffer, 2, 100);
}

void setBrightness(uint8_t bright) {
	uint8_t buffer[] = {0x00, bright};
	//HAL_SPI_Transmit(&hspi3, buffer, 2, 100);
}
