#include "FlowElement.h"
namespace spider {
FlowElement::FlowElement()
 : Element::Element()
{
    //ctor
}

FlowElement::FlowElement(Element *elm)
 : Element::Element(elm)
{
    //ctor
}

FlowElement::~FlowElement()
{
    //dtor
}
void FlowElement::pack() {
    int top = 0;
    int left = 0;
    for(std::list<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
        Element *child = (Element *)*it;
         if (!child->isVisible())
            continue;
        child->setY(top);
        child->setWidth(this->getWidth());
        child->pack();
        top += child->getHeight();
    }
}
}
