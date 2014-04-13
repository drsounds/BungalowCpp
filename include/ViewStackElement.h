#ifndef VIEWSTACKELEMENT_H
#define VIEWSTACKELEMENT_H
#include "Element.h"
namespace spider {
    class ViewStackElement : public Element {
    public:
        ViewStackElement() : Element() {}
        ViewStackElement(Element *parent) : Element(parent) {
        }
    };
}
#endif // VIEWSTACKELEMENT_H
