#include "TreeItem.h"
#include <regex>
namespace spider {
    TreeItem::TreeItem(Uri *uri) {
        this->uri = uri;
        this->setText("Loading...");
        if (std::regex_match(uri->uri, std::regex("spoyler:internal:start"))) {
            this->setText("Start");
        }
    }
}
