#pragma once
#include "spiderwin32.h"
COLORREF winspider::toWin32Color(spider::Color color) {
	return NULL;
}

winspider::Win32GraphicsContext::Win32GraphicsContext(HDC hDC) {
	this->hDC = hDC;
	this->controls = new map<string, HWND>();
}
winspider::Win32GraphicsContext::~Win32GraphicsContext() {

}
void winspider::Win32GraphicsContext::setOrigo(const int& x,const int& y) {
//	spider::GraphicsContext::setOrigo(x, y);
}
void winspider::Win32GraphicsContext::drawLine(int x1, int y1, int x2, int y2, spider::Color *color) {


}



void winspider::Win32GraphicsContext::drawRectangle(int x1, int y1, int x2, int y2, spider::Color *color) {
	HPEN hpen = CreatePen(PS_SOLID, 3, (RGB(255, 0, 0)));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	Rectangle(this->hDC, x1, y1, x2, y2);
	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void winspider::Win32GraphicsContext::fillRectangle(int x1, int y1, int x2, int y2, spider::Color *color) {
	HBRUSH hpen = CreateSolidBrush((RGB(color->getR(), color->getG(), color->getB())));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	RECT r;
	r.left = x1;
	r.right =  x1 + x2;
 	r.bottom =  y1 + y2;
	r.top = y1;
	FillRect(this->hDC, &r, hpen);

	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void winspider::Win32GraphicsContext::drawImage(spider::Image *img, int x1, int y1, int x2, int y2) {
}
void winspider::Win32GraphicsContext::drawString(string *text, spider::FontStyle *fs, spider::Color *color, int x1, int y, int w, int h) {

}
void winspider::Win32GraphicsContext::drawControl(int x, int y, int w, int h, char *name) {
    if (this->controls->find(name) != this->controls->end()) {

    } else {
        // Create control
//        HWND hwnd = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN, 350, 470, 100, 50, NULL, 0, hInst, 0);
  //      (*this->controls)[string(name)] = hwnd;
    }
}

