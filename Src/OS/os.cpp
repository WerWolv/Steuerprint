#include "os.h"

#include "screen.h"
#include "screen_home.h"
#include "renderer.h"
#include "layer.h"

#include <string>

extern "C" {
	#include "peripherals.h"
}

ScreenHome screenHome;

Screen *currScreen;

float OS::targetU = 0;
float OS::targetI = 0;
float OS::actualU = 0;
float OS::actualI = 0;

OS::OS() {
	this->running = false;
}

void OS::onInit(void) {
	this->running = true;
	
	currScreen = &screenHome;
}

void OS::mainEntry(void) {
	currScreen->render();
	Screen::renderer.swapBuffers();
}

void OS::onShutdown(void) {
	while(true);
}

void OS::onErrorOccured(uint8_t errorCode) {
	while(true);
}
