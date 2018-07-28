#include "screen.h"

Renderer Screen::renderer;

Screen::Screen() {
	this->renderer = Renderer();
}

void Screen::render(void) {
	renderer << this->bgLayer;
	renderer << Widget::widgetLayer;
	
	for(auto widget : this->m_widgets)
		widget->render();
}

void Screen::drawDefaultBackground() {	
	bgLayer.drawRect(0, 0, 121, 31, false, true);
}

void Screen::addWidget(Widget& widget) {
	this->m_widgets.push_back(&widget);
}
