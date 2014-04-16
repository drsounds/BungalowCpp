#include "TreeItem.h"
namespace spider {
    TreeItem::TreeItem(Uri *uri) {
        this->uri = uri;
        this->setText("Loading...");
    }
}
