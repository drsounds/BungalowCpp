#include "HBoxElement.h"
namespace spider {
    HBoxElement::HBoxElement()
    {
        //ctor
    }

    void HBoxElement::pack() {
        int height = this->getHeight();
        int flexes = 0;
        int statics = 0;
        int leftwidth = 0;
        int rightwidth = 0;
        int side = -1;
        // First calculate count of flex
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            if(child->hasAttribute("flex")) {
                flexes++;
                side = 0;
            } else {
                if(side == 0)
                    side+=1;
                if(side > 1)
                    side = 1;
                statics++;
                if(side < 1)
                    leftwidth += child->getWidth();
                else if(side > 0)
                    rightwidth += child->getWidth();
            }
        }

        int flexWidth = flexes > 0 ? (this->getWidth() - leftwidth - rightwidth) / flexes : 0;
        float flex = 1;
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            if(child->hasAttribute("flex")) {
        //		child->setWidth((flex / flexes) * flexWidth);
            //	flex = (int)child->getAttribute("flex");
                child->setWidth((1 / flexes) * flexWidth);
            } else {
                statics++;
            }
            child->setWidth(child->getWidth());
        }

        // Now assign elements
        int left = 0;
        int right = 0;
        side = -1;
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            if(child->hasAttribute("flex")) {

                side = 0;
            } else {
                if(side == 0)
                    side = 1;
            }
            if(side < 0)
                child->setX(left + child->getMargins()->left + this->getPadding()->left	);
            else if(side == 0) {
                child->setX(leftwidth + child->getMargins()->left);

            }
            else if(side > 0)
                child->setX(leftwidth + flexWidth + right );
            child->setY(this->getPadding()->top + child->getMargins()->top);

            child->setHeight(this->getHeight() - (this->getPadding()->bottom * 2 + child->getMargins()->bottom * 2));

            switch(side) {
                case -1:
                    left += child->getWidth();
                    break;
                case 0:
                    break;
                case 2:
                    right += child->getWidth();
                    break;
            }
        }



        // Pack child elements
        for(std::vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *child = (Element *)*it;
            child->pack();
        }

    };

}
