#include "libspider.h"
#include "Color.h"

namespace spider {
/**
Colors
**/
short Color::getR() {
	return this->r;
}
short Color::getG(){
	return this->g;
}
short Color::getB(){
	return this->b;
}
short Color::getA() {
	return this->a;
}
void Color::setR(short r) {
	this->r = r;
}
void  Color::setG(short g) {
	this->g = g;
}
void  Color::setB(short b){
	this->b = b;
}
void  Color::setA(short a){
	this->a = a;
}
Color::Color(short r, short g, short b, short a){
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
Color::Color(const string& html) {
	// TODO Fix this later
	int color = htmlToColor(html);

	short r, g, b;
	if(html.length() > 6 + 1) {
		r = color >> 16 + 8 & 0xff;
		g = color >> 16 & 0xff;
		b = color >> 8 & 0xff;
	} else {
		r = color >> 16 & 0xff;
		g = color >> 8 & 0xff;
		b = color >> 0 & 0xff;
	}
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
};
