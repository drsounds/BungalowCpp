#include "TabbarViewElement.h"
namespace spider {
    TabbarViewElement::TabbarViewElement()
     : ViewElement() {

    }
    TabbarViewElement::TabbarViewElement(Element *parent)
     : ViewElement::ViewElement(parent)
    {
        //ctor
        this->tabBar = new TabBarElement(parent);
        this->viewStack = new ViewStackElement(parent);
        this->appendChild(this->tabBar);
        this->tabBar->setHeight(28);
        this->tabBar->set("height", "28");
        this->viewStack->set("flex", "1");
        this->appendChild(this->viewStack);
    }
    bool TabbarViewElement::acceptsUri(string uri) {
        return false;
    }
    void TabbarViewElement::navigate(string uri) {
        this->viewStack->navigate(uri);
    }
    TabbarViewElement::~TabbarViewElement()
    {
        delete this->tabBar;
        delete this->viewStack;
    }
}
