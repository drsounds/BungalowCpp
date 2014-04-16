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
	list<Node *> *nodes = this->getChildNodes();
    if (this->getChildNodes()->size() < 1) {
        return;
    }
	Node *elm = (Node *)static_cast<spider::Node *>(*this->getChildNodes()->begin());
	Element *child = (Element *)elm;
	child->setX(0);
	child->setY(0);
	child->setWidth(this->getWidth());
	child->setHeight(this->getHeight());
	child->pack();

};
}
