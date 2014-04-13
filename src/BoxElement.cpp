#include "BoxElement.h"

namespace spider {
BoxElement::BoxElement()
{
    //ctor
}

BoxElement::~BoxElement()
{
    //dtor
}
/**
 Box Element
**/
void BoxElement::pack() {
	Element *child = static_cast<spider::Element *>(this->getChildNodes()->at(0));
	child->setX(0);
	child->setY(0);
	child->setWidth(this->getWidth());
	child->setHeight(this->getHeight());
};
}
