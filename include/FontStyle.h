#ifndef FONTSTYLE_H
#define FONTSTYLE_H
#include "libspider.h"
namespace spider {
    class FontStyle {
        int height;
        int weight;
        bool italic;
        bool underline;
        string *family;
    public:
        FontStyle(string *family, int height, int weight, bool italic, bool underline) {
            this->family = family;
            this->height = height;
            this->weight = weight;
            this->italic = italic;
            this->underline = underline;
        }
        int getHeight() {
            return this->height;
        }
        int getWeight() {
            return this->weight;
        }
        bool isItalic() {
            return this->italic;
        }
        bool isUnderline() {
            return this->underline;
        }
        string *getFamily() {
            return this->family;
        }

    };
}

#endif // FONTSTYLE_H
