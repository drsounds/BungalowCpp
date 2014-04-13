#include "TreeViewElement.h"
namespace spider {
TreeView::TreeView(Element *parent) {
	this->setParent(parent);
	this->mItems = new vector<TreeItem *>;

}

void TreeView::setItemHeight(int height) {
	this->itemHeight = height;

}

int TreeView::getItemHeight() {
	return this->itemHeight;

}

void TreeView::Draw(int x, int y, GraphicsContext *g) {
	int itemHeight = this->getItemHeight();

	int top = 0;
	for (vector<TreeItem *>::iterator it = this->mItems->begin(); it != this->mItems->end(); ++it) {
		TreeItem *item = static_cast<TreeItem *>(*it);
		g->drawString(item->text(), this->getFont(), (Color *)this->getObject("bgcolor"), 20, top, this->getWidth(), itemHeight);

		top += itemHeight;
	}
}

}

