#include "ButtonElement.h"

spider::ButtonElement::ButtonElement() {

	this->set("bgcolor", "#eeeeee");
}
void spider::ButtonElement::Draw(spider::GraphicsContext *c) {
	if(this->getInnerText() != NULL) {
		string *text = this->getInnerText();
		c->drawString(text, new FontStyle(new string("Tahoma"), 11, false, false, false), new Color(255, 255, 255, 255), this->getX(), this->getY(), 255, 16);
	}
}
