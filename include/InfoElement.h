#ifndef INFOELEMENT_H
#define INFOELEMENT_H
#include "HBoxElement.h"
namespace spider {
enum MessageType {
    Info, Warning, Error, Message
};
class InfoElement : public HBoxElement
{


    protected:
        MessageType type;
        HBoxElement *hbox;
    public:
        MessageType getType() {
            return this->type;
        }
        void setMessageType(MessageType type);
        InfoElement(Element *parent);
        virtual ~InfoElement();
        void show();
    private:
};
}
#endif // INFOELEMENT_H
