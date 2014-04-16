#include "ButtonElement.h"

spider::ButtonElement::ButtonElement()
: spider::Element() {

	this->set("bgcolor", new string("#eeeeee"));
}
void spider::ButtonElement::Draw(int x, int y, spider::GraphicsContext *c)
{
    spider::Element::Draw(x, y, c);
    if(this->getInnerText() != NULL) {
        spider::FontStyle *fontStyle = new FontStyle("Tahoma", 11, false, false, false);
		char *text = this->getInnerText();
		spider::rectangle tSize = c->measureString(text, fontStyle);
		int x = (this->getWidth() / 2) - (tSize.width / 2);
		int y = (this->getHeight() / 2) - (tSize.height / 2);

		c->drawString(text,fontStyle, new Color(255, 255, 255, 255), x, y, 255, 8);
		delete fontStyle;
	}
}
