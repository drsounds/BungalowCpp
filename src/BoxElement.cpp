#include "BoxElement.h"

namespace spider {
BoxElement::BoxElement()
 : Element()
{
    //ctor
}

BoxElement::BoxElement(Element *parent)
 : Element(parent)
{

}
BoxElement::~BoxElement()
{
    //dtor
}
/**
 Box Element
**/
void BoxElement::pack() {
    if (this->getChildNodes()->size() < 1) {
        return;
    }
	Element *child = static_cast<spider::Element *>(this->getChildNodes()->at(0));
	child->setX(0);
	child->setY(0);
	child->setWidth(this->getWidth());
	child->setHeight(this->getHeight());
};
}
