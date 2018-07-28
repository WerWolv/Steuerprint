#ifndef DISPLAY_H
#define DISPLAY_H

#include "main.h"

#define DISPLAY_ENABLE(x) 			(0xAE | (x & 0x01))		//true / false
#define DISPLAY_START_LINE(x) 		(0xC0 | (x & 0x1F))		//0-31
#define DISPLAY_PAGE(x)				(0xB8 | (x & 0x03))		//0-3
#define DISPLAY_COLUMN(x)			(0x00 | (x & 0x4F))		//0-79
#define DISPLAY_DIRECTION(x)		(0xA0 | (x & 0x01))		//0 / 1
#define DISPLAY_STATIC_DRIVER(x)	(0xA4 | (x & 0x01))		//true / false
#define DISPLAY_DUTY_CYCLE(x)		(0xA8 | (x & 0x01))		//0 / 1
#define DISPLAY_RMWO				(0xEE)
#define DISPLAY_RESET				(0xE2)

#define SCREEN_WIDTH 125
#define SCREEN_HEIGHT 32

typedef enum { LEFT, RIGHT, BOTH } Side;

extern void initDisplay(void);
extern void sendCommand(Side side, uint8_t data);
extern void sendData(Side side, uint8_t data);

extern void sendBuffer(bool buffer[SCREEN_WIDTH][SCREEN_HEIGHT]);

#endif
