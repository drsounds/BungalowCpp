#ifndef TREEITEM_H
#define TREEITEM_H
#include "Uri.h"
namespace spider {
    class TreeItem {
		string *title;
		string *subtitle;
		Uri *uri;
	public:
		TreeItem(Uri *uri);
		string *text() {
			return this->title;
		}
		~TreeItem();

	};
}
#endif // TREEITEM_H
