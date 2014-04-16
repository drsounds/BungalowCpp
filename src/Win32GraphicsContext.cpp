#pragma once
#include "Win32GraphicsContext.h"
namespace spider {
COLORREF toWin32Color(Color color) {
	return NULL;
}
void Win32GraphicsContext::setClip(rectangle rect) {
    if (rect.width == 0 || rect.height == 0) {
        SelectClipRgn(this->hDC, NULL);
    }
    HRGN region = CreateRectRgn(rect.x, rect.y, rect.width, rect.height);


    SelectClipRgn(this->hDC, region);
}
Win32GraphicsContext::Win32GraphicsContext(HWND hWnd, HDC hDC) {
	this->hDC = hDC;
	this->controls = new map<string, HWND>();
	this->hWnd = hWnd;
}
Win32GraphicsContext::~Win32GraphicsContext() {

}
void Win32GraphicsContext::setOrigo(const int& x,const int& y) {
//	spider::GraphicsContext::setOrigo(x, y);
}
void Win32GraphicsContext::drawLine(int x1, int y1, int x2, int y2, Color *color) {


}


void Win32GraphicsContext::invalidateRegion(spider::rectangle rect) {
    LPRECT rgn;
    rgn->left = rect.x;
    rgn->right = rect.width + rect.x;
    rgn->bottom = rect.y + rect.height;
    rgn->top = rect.y;
    InvalidateRect(this->hWnd, rgn, TRUE);
}
void Win32GraphicsContext::drawRectangle(int x1, int y1, int x2, int y2, Color *color) {
	HPEN hpen = CreatePen(PS_SOLID, 3, (RGB(255, 0, 0)));
	HGDIOBJ old = SelectObject(this->hDC, hpen);
	Rectangle(this->hDC, x1, y1, x2, y2);
	SelectObject(this->hDC, old);
	DeleteObject(hpen);
}
void Win32GraphicsContext::fillRectangle(int x1, int y1, int x2, int y2, Color *color) {
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
void Win32GraphicsContext::drawImage(Image *img, int x1, int y1, int x2, int y2) {
}
rectangle Win32GraphicsContext::measureString(char *text, FontStyle *font) {
    SIZE sizeText;
    GetTextExtentPoint32(this->hDC, (char *)text, lstrlen(text), &sizeText);
    spider::rectangle rect;
    rect.width = sizeText.cx;
    rect.height = sizeText.cy;

    return rect;
}
void Win32GraphicsContext::drawString(char *text, FontStyle *fs, spider::Color *color, int x, int y, int w, int h) {
    HFONT font = CreateFont(fs->getHeight(), fs->getHeight() / 2, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS,  CLIP_MASK, DEFAULT_QUALITY, FF_MODERN, fs->getFamily());
    SetBkMode(this->hDC, TRANSPARENT);
    COLORREF col = RGB(color->getR(), color->getG(), color->getB());
    SetTextColor(this->hDC, col);
    SelectObject(this->hDC, font);
    TextOut(this->hDC, x, y, (LPCSTR)text, 12);

    DeleteObject(font);
}
void Win32GraphicsContext::drawControl(int x, int y, int w, int h, char *name) {
    if (this->controls->find(name) != this->controls->end()) {

    } else {
        // Create control
//        HWND hwnd = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN, 350, 470, 100, 50, NULL, 0, hInst, 0);
  //      (*this->controls)[string(name)] = hwnd;
    }
}
}

