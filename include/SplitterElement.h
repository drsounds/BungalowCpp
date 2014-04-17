#ifndef SPLITTERELEMENT_H
#define SPLITTERELEMENT_H
#include "Element.h"
namespace spider {
class SplitterElement : public Element
{
    public:
        SplitterElement(Element *parent);
        virtual ~SplitterElement();
    protected:
    private:
};
}

#endif // SPLITTERELEMENT_H
