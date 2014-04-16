#ifndef FLOWELEMENT_H
#define FLOWELEMENT_H
#include "Element.h"
namespace spider {
class FlowElement : public Element
{
    public:
        FlowElement();
        FlowElement(Element *parent);
        virtual ~FlowElement();
        void pack();
    protected:
    private:
};
}
#endif // FLOWELEMENT_H
