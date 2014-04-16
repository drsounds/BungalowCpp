#include "TreeViewElement.h"
#include "WindowElement.h"
#include "Win32WindowElement.h"
namespace spider {
void treeview_mousedown(SPType *sender, EventArgs *e) {
    MouseEventArgs *args = (MouseEventArgs *)e;
    TreeViewElement *treeView = (TreeViewElement *)sender;
    int top = 0;
    int y = args->getY() - treeView->getAbsoluteBounds()->y;
    rectangle *bounds = treeView->getAbsoluteBounds();
	for (list<TreeItem *>::iterator it = treeView->items()->begin(); it != treeView->items()->end(); ++it) {
		TreeItem *item = static_cast<TreeItem *>(*it);
		if (args->getY() > top + treeView->getY() && args->getY() < top + treeView->getY() + treeView->getItemHeight()) {
            item->setSelected(true);

            // Raise treeview itemselected event
            TreeViewEventArgs *eventArgs = new TreeViewEventArgs();
            eventArgs->setItem(item);
            treeView->notify(string("itemselected"), treeView, eventArgs);

		} else {
            item->setSelected(false);
		}
		top += treeView->getItemHeight();
	}
	Win32WindowElement * winElement = (Win32WindowElement *)treeView->getWindowElement();
	rectangle region;
	region.x = treeView->getX();
	region.y = treeView->getY();
	region.z = 0;
	region.width = treeView->getWidth();
	region.height = treeView->getHeight();
	winElement->invalidateRegion(region);
}
TreeViewElement::TreeViewElement(Element *parent)
: Element(parent) {
	this->setParent(parent);
	this->mItems = new list<TreeItem *>;
	this->itemHeight = 18;
	this->addEventListener(string("mousedown"), (s_event)&treeview_mousedown);
	this->setWindowElement(NULL);
}

void TreeViewElement::addItem(TreeItem *item) {
    this->mItems->push_back(item);
}
void TreeViewElement::setItemHeight(int height) {
	this->itemHeight = height;

}

int TreeViewElement::getItemHeight() {
	return this->itemHeight;

}

void TreeViewElement::Draw(int x, int y, GraphicsContext *g) {
    spider::Element::Draw(x, y, g);
	int itemHeight = this->getItemHeight();

	int top = 0;
	for (list<TreeItem *>::iterator it = this->mItems->begin(); it != this->mItems->end(); ++it) {
		TreeItem *item = static_cast<TreeItem *>(*it);
		if (item->isSelected()) {
            g->fillRectangle(x, y + top , this->getWidth(), itemHeight, new Color(244, 255, 255, 255));
		}
		Color *color =  item->isSelected() ? (Color *)new Color(0, 0, 0, 255) : (Color *)this->getAttributeObj("fgcolor");
		rectangle strB = g->measureString(item->text(), font);
        int ttop = (top + (itemHeight / 2)) - (strB.height / 2);
		g->drawString(item->text(), this->getFont(), (Color *)color, 20 + x, y + ttop, this->getWidth(), itemHeight);

		top += itemHeight;
	}
}

}

