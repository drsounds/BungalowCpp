#include "ViewElement.h"
namespace spider {
ViewElement::ViewElement()
 : VBoxElement::VBoxElement()
{

    //ctor
}
void ViewElement::pack() {
    VBoxElement::pack();
}

ViewElement::ViewElement(Element *parent)
 : VBoxElement::VBoxElement(parent)
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
