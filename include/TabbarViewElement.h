#ifndef TABBARVIEWELEMENT_H
#define TABBARVIEWELEMENT_H

#include "Element.h"
#include "ViewElement.h"
#include "TabBarElement.h"
#include "ViewStackElement.h"
namespace spider {
class TabbarViewElement : public ViewElement
{
    public:
        TabbarViewElement();
        TabbarViewElement(Element *parent);
        virtual ~TabbarViewElement();
        virtual void navigate(string uri);
        virtual bool acceptsUri(string uri);
    protected:
        ViewStackElement *viewStack;
        TabBarElement *tabBar;

    private:
};
}

#endif // TABBARVIEWELEMENT_H
