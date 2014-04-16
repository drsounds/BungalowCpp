#ifndef TEXTELEMENT_H
#define TEXTELEMENT_H
#include "Element.h"
#include "GraphicsContext.h"
#include "Color.h"
#include "FontStyle.h"
#include <string>
using namespace std;
namespace spider {
class TextElement : public Element
{
    public:
        TextElement();
        TextElement(Element *parent);

        virtual ~TextElement();
        void Draw(int x, int, GraphicsContext *gc);
    protected:

    private:
        string text;
};
}
#endif // TEXTELEMENT_H
