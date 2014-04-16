#include "TreeViewElement.h"
namespace spider {
void treeview_mousedown(SPType *sender, EventArgs *e) {
    MouseEventArgs *args = (MouseEventArgs *)e;
    TreeViewElement *treeView = (TreeViewElement *)sender;
    int top = 0;
	for (vector<TreeItem *>::iterator it = treeView->items()->begin(); it != treeView->items()->end(); ++it) {
		TreeItem *item = static_cast<TreeItem *>(*it);
		if (args->getY() > top + treeView->getY() && args->getY() < top + treeView->getY() + treeView->getItemHeight()) {
            item->setSelected(true);

		} else {
            item->setSelected(false);
		}
		top += treeView->getItemHeight();
	}
}
TreeViewElement::TreeViewElement(Element *parent)
: Element(parent) {
	this->setParent(parent);
	this->mItems = new vector<TreeItem *>;
	this->itemHeight = 18;
	this->addEventListener(string("mousedown"), (s_event)&treeview_mousedown);
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
	int itemHeight = this->getItemHeight();

	int top = 0;
	for (vector<TreeItem *>::iterator it = this->mItems->begin(); it != this->mItems->end(); ++it) {
		TreeItem *item = static_cast<TreeItem *>(*it);
		if (item->isSelected()) {
            g->fillRectangle(x, y + top , this->getWidth(), itemHeight, new Color(244, 255, 255, 255));
		}
		Color *color =  item->isSelected() ? (Color *)new Color(0, 0, 0, 255) : (Color *)this->getAttributeObj("fgcolor");
		g->drawString(item->text(), this->getFont(), (Color *)color, 20 + x, y + top, this->getWidth(), itemHeight);

		top += itemHeight;
	}
}

}

