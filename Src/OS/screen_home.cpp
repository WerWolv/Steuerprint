#include "screen_home.h"
#include "os.h"
#include "Settings.h"

enum { VOLTAGE, CURRENT, DEFAULT } Mode = DEFAULT;

enum { HOME, BATTERY_CHARGE, FUNCTION_GENERATOR, SETTINGS } Menu = HOME;

uint8_t segments[10] = { 0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6 };

ScreenHome::ScreenHome() : Screen() {

}

void draw7SegNumber(Layer &layer, uint8_t x, uint8_t y, uint8_t number, bool dot) {
	if(segments[number] & 0x01 << 7)
		layer.drawRect(x + 2, y, x + 9, y + 1, true, true); 		// A
	if(segments[number] & 0x01 << 6)
		layer.drawRect(x + 10, y + 2, x + 11, y + 9, true, true); 	// B
	if(segments[number] & 0x01 << 5)
		layer.drawRect(x + 10, y + 12, x + 11, y + 19, true, true); // C
	if(segments[number] & 0x01 << 4)
		layer.drawRect(x + 2, y + 20, x + 9, y + 21, true, true);	// D
	if(segments[number] & 0x01 << 3)
		layer.drawRect(x, y + 12, x + 1, y + 19, true, true); 		// E
	if(segments[number] & 0x01 << 2)
		layer.drawRect(x, y + 2, x + 1, y + 9, true, true); 		// F
	if(segments[number] & 0x01 << 1)
		layer.drawRect(x + 2, y + 10, x + 9, y + 11, true, true);	// G
	
	layer.drawRect(x + 12, y + 20, x + 13, y + 21, true, dot); 		// Dot
}

void drawBigNumber(Layer &layer, uint8_t x, uint8_t y, uint8_t number) {
 for(uint8_t i = 0; i < 10; i++)
        for(uint8_t j = 0; j < 16; j++)
            layer.drawPoint(x + i + 2, y + j + 2, (fontTextBig[number][i] & 0x01 << j) >> j);

}

void ScreenHome::render(void) {
	static uint32_t displayTime = 0;
    static float oldU, oldI;
	
	Screen::render();
	
	this->drawDefaultBackground();
			
	if(oldU != OS::targetU) {
		displayTime = 100;
		Mode = VOLTAGE;
	} else if(oldI != OS::targetI) {
		displayTime = 100;
		Mode = CURRENT;
	}
	
    oldU = OS::targetU;
    oldI = OS::targetI;
    
	this->m_voltage = OS::actualU;
	this->m_current = OS::actualI;
	
	char valueStr[10];
	float intpart;
	
	bgLayer.drawLine(2, 10, 119, 10, true);
	bgLayer.drawLine(60, 2, 60, 9, true);
	bgLayer.drawString("Voltage", 2, 0, false, true);
	bgLayer.drawString("Current", 75, 0, false, true);

	drawBigNumber(bgLayer, 2, 12,  (uint32_t) (m_voltage - (uint32_t) m_voltage % 10) / 10);
	drawBigNumber(bgLayer, 11, 12, (uint32_t) m_voltage % 10);
	drawBigNumber(bgLayer, 22, 12, modf(m_voltage, &intpart) * 10);

	drawBigNumber(bgLayer, 67, 12, ((uint16_t) m_current % 10000) / 1000);
	drawBigNumber(bgLayer, 76, 12, ((uint16_t) m_current % 1000) / 100);
	drawBigNumber(bgLayer, 85, 12, ((uint16_t) m_current % 100) / 10);
	drawBigNumber(bgLayer, 94, 12, ((uint16_t) m_current % 10));

	bgLayer.drawPoint(23, 26, true);
	bgLayer.drawPoint(23, 27, true);
	bgLayer.drawPoint(22, 28, true);

	bgLayer.drawString("V", 32, 18, false, true);
	bgLayer.drawString("mA", 104, 18, false, true);
	
	
	if(displayTime > 0)
		displayTime--;
	if(displayTime == 1)
		Mode = DEFAULT;
	
	switch(Mode) {
		case VOLTAGE:
			bgLayer.drawRect(11, 6, 105, 29, false, true);
			bgLayer.drawRect(12, 3, 108, 28, true, false);
			bgLayer.drawRect(12, 3, 108, 28, false, true);
		
			std::sprintf(valueStr, "%*d mA", 7, (uint16_t) this->m_current);
			this->bgLayer.drawString(valueStr, 45, 5, false, true);
		
			draw7SegNumber(this->bgLayer, 19, 5, (uint32_t) (m_voltage - (uint32_t) m_voltage % 10) / 10, false);
			draw7SegNumber(this->bgLayer, 33, 5, (uint32_t) m_voltage % 10, true);
			draw7SegNumber(this->bgLayer, 47, 5, modf(m_voltage, &intpart) * 10, false);

			bgLayer.drawLine(70, 17, 100, 17, true);
		
			this->bgLayer.drawString("V", 59, 18, false, true);	
		break;
		
		case CURRENT:
			bgLayer.drawRect(11, 6, 105, 29, false, true);
			bgLayer.drawRect(12, 3, 108, 28, true, false);
			bgLayer.drawRect(12, 3, 108, 28, false, true);
		
			std::sprintf(valueStr, "%*.1f V", 6, this->m_voltage);
			this->bgLayer.drawString(valueStr, 56, 5, false, true);	
			
			if(((uint16_t) m_current % 10000) / 1000 == 1)
				draw7SegNumber(this->bgLayer, 5, 5,  ((uint16_t) m_current % 10000) / 1000, false);
			
			draw7SegNumber(this->bgLayer, 19, 5,  ((uint16_t) m_current % 1000) / 100, false);
			draw7SegNumber(this->bgLayer, 33, 5, ((uint16_t) m_current % 100) / 10, false);
			draw7SegNumber(this->bgLayer, 47, 5, ((uint16_t) m_current % 10), false);
			
			bgLayer.drawLine(70, 17, 100, 17, true);
		
			this->bgLayer.drawString("mA", 59, 18, false, true);
		break;
		
		default: break;
	}		
}
void ScreenHome::onHardwareButtonPressed(bool btnA, bool btnB, bool btnC) {
	
}

void ScreenHome::onHardwareEncoderTurned(int8_t steps) {
	
}
