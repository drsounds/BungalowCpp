#include "TextElement.h"
namespace spider {
    TextElement::TextElement()
    {
        //ctor
    }
    TextElement::TextElement(Element *parent)
        : Element(parent)
    {

    }
    /**
     *
     **/
    void TextElement::Draw(int x, int y, GraphicsContext *gc) {
        gc->drawString(this->text, new FontStyle(string("MS Sans Serif"), 8, 1, FALSE, FALSE), static_cast<Color *>(this->get("fgcolor")), x, y, this->getWidth(), this->getHeight());

    }

    TextElement::~TextElement()
    {
        //dtor
    }
}
