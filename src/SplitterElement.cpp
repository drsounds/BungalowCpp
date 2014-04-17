#include "SplitterElement.h"
namespace spider {
SplitterElement::SplitterElement(Element *parent)
 : Element(parent)
{
    //ctor
    this->set("width", "1");
    this->set("bgcolor", "#111111");
}

SplitterElement::~SplitterElement()
{
    //dtor
}
}
