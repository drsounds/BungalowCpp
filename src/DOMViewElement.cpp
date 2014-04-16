#include "DOMViewElement.h"
#include "VBoxElement.h"
#include "HBoxElement.h"
#include "ButtonElement.h"
namespace spider {

    Element *p_parent;
    void DOMViewElement::loadXML(char *buffer) {
        this->getChildNodes()->clear();
        this->parseDepth = 0;
        XML_Parser parser = XML_ParserCreate(NULL);
        XML_SetUserData(parser, this);
        int len = sizeof(buffer);
        bool done = false;
        p_parent = this;
        XML_SetElementHandler(parser, &startElement, endElement);
        do {

            if (!XML_Parse(parser, buffer, len, done)) {


            }
        } while (!done);
        XML_ParserFree(parser);


    }

    char *getAttribute(const char *attribute, const char **attributes, const char *defValue) {
        int count = sizeof(attributes);
        for (int i = 0; i < count / 2; i += 2) {
            const char *attr = attributes[i];
            const char *val = attributes[i+1];
            if (string(attr) == string(attribute)) {
                delete attr;
                return (char *)val;
            }
        }
        return (char *)defValue;
    }

    void startElement(void *data, const char *el, const char **attr) {
        string t = string(el);
        DOMViewElement *view = (DOMViewElement *)data;
        Element *elm = NULL;
        if (t == string("vbox")) {
            VBoxElement *vbox = new VBoxElement(p_parent);

            elm = vbox;
        }
        if (t == string("hbox")) {
            HBoxElement *hbox = new HBoxElement(p_parent);


            elm = hbox;
        }
        if (t == string("image")) {

        }
        if (t == string("button")) {
            ButtonElement *button = new ButtonElement(p_parent);
            elm = button;
        }

        // Get common attributes
        char *flex = getAttribute("flex", attr, NULL);
        if (flex != NULL) {
            elm->set(string("flex"), new string(flex));

        }
        p_parent->appendChild(elm);
        view->parseDepth++;
        p_parent = elm;
    }

    void endElement(void *data, const char *el) {
        DOMViewElement *view = (DOMViewElement *)data;
        p_parent = (Element *)p_parent->getParent();
        view->parseDepth--;

    }
}
