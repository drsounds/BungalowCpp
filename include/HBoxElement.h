#ifndef HBOXELEMENT_H
#define HBOXELEMENT_H
#include "Element.h"
namespace spider {
    class HBoxElement : public Element {

    public:
        HBoxElement(Element *parent) : Element(parent) {

        }
        HBoxElement();
        void pack();
    };
}
#endif // HBOXELEMENT_H
