#include "TabBarElement.h"
namespace spider {

Tab::Tab(TabBarElement *tabBar, string *name, string *id, string *uri) {
    this->tabBar = tabBar;
    this->name = name;
    this->id = id;
    this->uri = uri;
}
void TabBarElement::addTab(string *id, string *name, string *uri) {
    Tab *tab = new Tab(this, id, name, uri);
    this->tabs->push_back(tab);
    if (this->tabs->size() == 1) {
        this->activeTab = tab;
    }
}

TabBarEventArgs::TabBarEventArgs(Tab *tab) {
    this->tab = tab;
}

void TabBarElement::mousedown(int mouseButton, int x, int y) {
    int left = 0;
    std::list<Tab *>::iterator it = this->tabs->begin();
    do {
        Tab *tab = (Tab *)static_cast<Tab *>(*it);
        string *title = tab->name;
        string *id = tab->id;
        string *uri = tab->uri;
        FontStyle *font = (FontStyle *)this->getAttributeObj("font");
        GraphicsContext *g = this->createGraphics();
        rectangle strSize = g->measureString((char *)title->c_str(), font);
        int with = 20 + strSize.width + 20;
        if (x > left && x < left + width) {
            this->activeTab = tab;
            TabBarEventArgs *args = new TabBarEventArgs(tab);
            this->notify(string("tabselected"), (SPType *)this, (EventArgs *)args);
        }
        left += width;
        ++it;
    } while (it != this->tabs->end());
    this->invalidate();
}
TabBarElement::TabBarElement()
 : Element()
{
    //ctor
    this->tabs = new std::list<Tab *>;
    this->set("active_tab_fgcolor", "#ffffff");
    this->set("active_tab_bgcolor", "#474747");

}
TabBarElement::TabBarElement(Element *parent)
 : Element(parent)
{
    //ctor
    this->tabs = new std::list<Tab *>;
    this->set("active_tab_fgcolor", "#ffffff");
    this->set("active_tab_bgcolor", "#474747");
    this->set("bgcolor", "#565656");

}
void TabBarElement::Draw(int x, int y, GraphicsContext *g) {
    g->fillRectangle(x, y, this->getWidth(), this->getHeight(), (Color *)this->getAttributeObj("bgcolor"));
    int left = 0;
    std::list<Tab *>::iterator it = this->tabs->begin();
    do {
        Color *fgColor = (Color *)this->getAttributeObj("fgcolor");

        Tab *tab = (Tab *)static_cast<Tab *>(*it);

        string *title = tab->getName();
        string *id = tab->getId();
        rectangle strSize = g->measureString((char *)title->c_str(), font);
        int width = 20 + strSize.width + 20;
        if (this->activeTab == tab) {
            fgColor = (Color *)this->getAttributeObj("active_tab_fgcolor");
            Color *bgColor = (Color *)this->getAttributeObj("active_tab_bgcolor");
            g->fillRectangle(x + left, y, width, this->getHeight(), bgColor);
        }
        g->drawString((char *)title->c_str(), font, fgColor, left + x + 20, y + (this->getHeight() / 2) - (strSize.height / 2), strSize.width, strSize.height);
        left += width;
        ++it;
    } while (it != this->tabs->end());
}


TabBarElement::~TabBarElement()
{
    //dtor
}
}
