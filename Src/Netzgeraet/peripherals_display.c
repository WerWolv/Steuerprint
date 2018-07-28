#include "peripherals.h"
#include "display.h"

void sendDataLeft(uint8_t data) {
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, 0x7F << 3, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, (data & 0x7F) << 3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x80) == 0x80 ? GPIO_PIN_SET : GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(LCD_EN1_GPIO_Port, LCD_EN1_Pin, GPIO_PIN_SET);
	delayUs(5);
	HAL_GPIO_WritePin(LCD_EN1_GPIO_Port, LCD_EN1_Pin, GPIO_PIN_RESET);
}

void sendDataRight(uint8_t data) {
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, 0x7F << 3, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, (data & 0x7F) << 3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x80) == 0x80 ? GPIO_PIN_SET : GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_SET);
	
	HAL_GPIO_WritePin(LCD_EN2_GPIO_Port, LCD_EN2_Pin, GPIO_PIN_SET);
	delayUs(5);
	HAL_GPIO_WritePin(LCD_EN2_GPIO_Port, LCD_EN2_Pin, GPIO_PIN_RESET);
}

void sendCommandLeft(uint8_t data) {
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, 0xFF << 3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, (data & 0x7F) << 3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x80) == 0x80 ? GPIO_PIN_SET : GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_EN1_GPIO_Port, LCD_EN1_Pin, GPIO_PIN_SET);
	delayUs(5);
	HAL_GPIO_WritePin(LCD_EN1_GPIO_Port, LCD_EN1_Pin, GPIO_PIN_RESET);
}

void sendCommandRight(uint8_t data) {
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, 0xFF << 3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, (data & 0x7F) << 3, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x80) == 0x80 ? GPIO_PIN_SET : GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_EN2_GPIO_Port, LCD_EN2_Pin, GPIO_PIN_SET);
	delayUs(5);
	HAL_GPIO_WritePin(LCD_EN2_GPIO_Port, LCD_EN2_Pin, GPIO_PIN_RESET);
}

void sendCommand(Side side, uint8_t data) {
	switch(side) {
		case LEFT: sendCommandLeft(data); break;
		case RIGHT: sendCommandRight(data); break;
		case BOTH: 
					sendCommandLeft(data);
					sendCommandRight(data);
		break;
	}
}

void sendData(Side side, uint8_t data) {
	switch(side) {
		case LEFT: sendDataLeft(data); break;
		case RIGHT: sendDataRight(data); break;
		case BOTH: 
					sendDataLeft(data);
					sendDataRight(data);
		break;
	}
}

void initDisplay(void) {
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, 0xFF << 3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_EN1_GPIO_Port, LCD_EN1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_EN2_GPIO_Port, LCD_EN2_Pin, GPIO_PIN_RESET);
	
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_RESET_GPIO_Port, LCD_RESET_Pin, GPIO_PIN_SET);
	HAL_Delay(10);
	
	HAL_GPIO_WritePin(LCD_CD_GPIO_Port, LCD_CD_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, GPIO_PIN_SET);
	
	sendCommand(BOTH, DISPLAY_RESET);
	HAL_Delay(10);
	sendCommand(BOTH, DISPLAY_STATIC_DRIVER(false));
	sendCommand(BOTH, DISPLAY_DUTY_CYCLE(1));
	sendCommand(BOTH, DISPLAY_DIRECTION(0));
	sendCommand(BOTH, DISPLAY_RMWO);
	sendCommand(BOTH, DISPLAY_START_LINE(0));
	sendCommand(BOTH, DISPLAY_ENABLE(true));
}


void sendBuffer(bool buffer[SCREEN_WIDTH][SCREEN_HEIGHT]) {
	uint8_t x, y, byte, page = 0;								
    
    for(page = 0; page < 4; page++) {				
        sendCommand(BOTH, DISPLAY_COLUMN(0x00));	
        sendCommand(BOTH, DISPLAY_PAGE(page));		
        for(x = 0; x < SCREEN_WIDTH; x++) {			
            byte = 0;								
            for(y = 0; y < 8; y++) {				
                byte |= buffer[x][y+(8 * page)] << y;
            }
            sendData(x > 60 ? RIGHT : LEFT, byte);						
        }
    }
}
