#include "ViewElement.h"
namespace spider {
ViewElement::ViewElement()
 : FlowElement::FlowElement()
{
    //ctor
}

ViewElement::ViewElement(Element *parent)
 : FlowElement::FlowElement(parent)
{
    //ctor
}
void ViewElement::navigate(string uri) {
}
ViewElement::~ViewElement()
{
    //dtor
}
}
