#include "Uri.h"

namespace spider {
   Uri::Uri(char *uri) {
        this->uri = uri;
   }
   Uri::~Uri() {
        free(this->uri);
   }
}
