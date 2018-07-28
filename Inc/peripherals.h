#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include "stm32f4xx_hal.h"

#include "Settings.h"

typedef enum { I_IST = 1, U_IST = 2, TEMP = 0 } ADC_Data;
typedef enum { U_SOLL, I_SOLL } DAC_Data;
typedef enum { ENCODER_A, ENCODER_B } Encoder;
typedef enum { ENCODER_LEFT = -1, ENCODER_RIGHT = 1 } EncoderDir;

typedef void (*EncoderTurnedCallback_fptr)(int8_t steps);
typedef void (*ButtonCallback_fptr)(void);
typedef void (*USBReceivedCallback_fptr)(const char* str, uint16_t length);

extern void initADC(ADC_HandleTypeDef *adcHandler);
extern float getADCValue(ADC_Data data);
 
extern void initCallbacks(void);
extern void addEncoderATurnedCallback(EncoderTurnedCallback_fptr fptr);
extern void addEncoderBTurnedCallback(EncoderTurnedCallback_fptr fptr);
extern void addEncoderAButtonCallback(ButtonCallback_fptr fptr);
extern void addEncoderBButtonCallback(ButtonCallback_fptr fptr);
extern void addFuseButtonCallback(ButtonCallback_fptr fptr);
extern void addOutputButtonCallback(ButtonCallback_fptr fptr);
extern void addUSBReceivedCallback(USBReceivedCallback_fptr fptr);
extern void handleEncoderCallbacks(void);
 
extern void initDAC(DAC_HandleTypeDef *dacHandler, TIM_HandleTypeDef *timerHandler);
extern void setDACValue(DAC_Data data, float value);
 
extern void initEncoder(TIM_HandleTypeDef *timHandleA, TIM_HandleTypeDef *timHandleB);
extern EncoderDir getEncoderTurnDir(Encoder encoder);

extern void setBrightness(uint8_t percent);
extern void setContrast(uint8_t percent);

extern void initUsDelay(void);
extern __INLINE void delayUs(volatile uint32_t us);

#endif
