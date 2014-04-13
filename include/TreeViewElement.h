#ifndef TREEVIEWELEMENT_H
#define TREEVIEWELEMENT_H
#include "Uri.h"
#include "Element.h"
#include "TreeItem.h"
namespace spider {

    class TreeView : public Element {
	private:
		vector<TreeItem *> *mItems;
		int itemHeight;
	public:
		TreeView(Element *parent);

		void Draw(int x, int y, GraphicsContext *g);

		void setItemHeight(int height);
		int getItemHeight();

	};


}
#endif // TREEVIEWELEMENT_H
