#ifndef LINKELEMENT_H
#define LINKELEMENT_H
#include "TextElement.h"

namespace spider {
class LinkElement : public TextElement
{
    public:
        LinkElement(Element *parent);
        virtual ~LinkElement();
    protected:
    private:
};
}

#endif // LINKELEMENT_H
