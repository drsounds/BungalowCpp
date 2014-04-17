#include "InfoElement.h"
#include "TextElement.h"
namespace spider {
    InfoElement::InfoElement(Element *parent)
     : Element(parent)
    {
        //ctor
        this->set("height", "32");
        this->getPadding()->top = 20;
        this->getPadding()->left = 20;
        this->getPadding()->right = 20;
        this->getPadding()->bottom = 20;


        this->hbox = new HBoxElement(this);
        HBoxElement *spacer = new HBoxElement(hbox);
        spacer->set("width", "128");
        this->hbox->appendChild(spacer);
        TextElement *text = new TextElement(hbox);
        text->set("flex", "1");


    }
    void InfoElement::show(MessageType type, char *text) {
        this->setMessageType(type);

    }
    void InfoElement::setMessageType(MessageType type) {
        this->type = type;
        switch(type) {
        case MessageType.Warning:
            this->set("bgcolor", "#ffffaa");
            break;
        case MessageType.Info:
            this->set("bgcolor", "#00ffff");
            break;
        case MessageType.Error:
            this->set("bgcolor", "#ffeeee");
            break;
        case MessageType.Message:
            this->set("bgcolor", "#eeffee");
            break;
        }
    }
    InfoElement::~InfoElement()
    {
        //dtor
    }
}
