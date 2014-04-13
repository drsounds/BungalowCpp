#ifndef INPUTELEMENT_H
#define INPUTELEMENT_H
#include "Element.h"
#include "GraphicsContext.h"
namespace spider {
class InputElement : public Element
{
private:
    public:
        InputElement();
        InputElement(Element *parent);
        virtual ~InputElement();
        void draw(GraphicsContext *gc);
    protected:
    private:
};
}
#endif // INPUTELEMENT_H
