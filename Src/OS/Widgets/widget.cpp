#include "widget.h"

Layer Widget::widgetLayer;

Widget::Widget(uint8_t x, uint8_t y, uint8_t width, uint8_t height, int8_t tabIndex) : m_x(x), m_y(y), m_width(width), m_height(height), m_tabIndex(tabIndex) {
	
}

Widget::~Widget() {
	
}

void Widget::renderSelected() {
	Widget::widgetLayer.drawRect(m_x - 2, m_y - 2, m_x + m_width + 2, m_y + m_height + 2, false, true);
}

void Widget::select() {
	this->m_selected = true;
	this->onSelected();
}

void Widget::unselect() {
	this->m_selected = false;
	this->onUnselected();
}
