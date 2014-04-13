#ifndef ELEMENT_H
#define ELEMENT_H
#include "Node.h"
#include "Observer.h"
#include "FontStyle.h"
#include "GraphicsContext.h"
namespace spider {
    class Element : public Node {
    private:
        int width;
        int height;
        int x;
        int y;
        int z;
        bool visible;
        margin *margins;
        margin *padding;
        std::vector<Observer *> *observers;
        map<string, void *> *properties;
        map<string, string> *attributes;
        FontStyle *font;
        string *id;
        string *data;
    public:
        void set(const string& title, const string& val);
        virtual void Draw(int x, int y, GraphicsContext *c);
        string getType() {
            return "Element";
        }
        bool isVisible() {
            return this->visible;
        }
        void setVisible(bool visible) {
            this->visible = visible;
        }

        void notify(string evt, void *data);
        FontStyle *getFont() {
            return this->font;
        }
        void setFont(FontStyle *font)  {
            this->font = font;
        }
        Element();
        Element(Element *parent);
        ~Element();
        int getX();
        margin *getMargins();
        margin *getPadding();
        string *getInnerText();
        void setInnerText(string *data);
        void addEventListener(string evt, s_event callback);
        void mouseMove(int& x, int& y);
        void mouseClick(int& mouseButton, int& x, int& y);
        void click(int mouseButton, int x, int y);
        int getY();
        int getWidth();
        int getHeight();
        int getZ();
        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setZ(int z);

        bool hasAttribute(string attrib);
        string *getAttribute(string title);
        void *getAttributeObj(string title);
        void setAttribute(string attribute, string value);
        string *getId();
        void setId(string *id);
        virtual void pack() {}

    };
}
#endif // ELEMENT_H
