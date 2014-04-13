#include "InputElement.h"
namespace spider {
InputElement::InputElement()
{
    //ctor
}

InputElement::~InputElement()
{

}
InputElement::InputElement(Element *parent)
    : Element(parent) {

}

void InputElement::draw(GraphicsContext *gc) {

}
}
