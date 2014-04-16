#include "WhatsNewView.h"
#include "ButtonElement.h"
#include "HBoxElement.h"
namespace spider {
    namespace views {
        WhatsNewView::WhatsNewView()
         : ViewElement::ViewElement()
        {
            //ctor
        }
        WhatsNewView::WhatsNewView(Element *parent)
         : ViewElement::ViewElement(parent)
        {

            // Build the view
            HBoxElement *hbox = new HBoxElement(this);
            hbox->getPadding()->top = 12;
            hbox->getPadding()->left = 6;
            hbox->getPadding()->bottom = 12;
            hbox->getPadding()->right =  16;



            hbox->set("height", "60");

            this->appendChild(hbox);

            // Add Header
            HBoxElement *title = new HBoxElement(hbox);
            title->set("fgcolor", "#aaffaa");
            title->setInnerText("What's New\0");
            title->set("height", "60");
            title->set("width", "120");
            title->set("size", "12");
            hbox->appendChild(title);

            // Add flex
            HBoxElement *hspacer = new HBoxElement(hbox);
            hspacer->set("flex", "1");
            hspacer->set("width", "100%");
            hspacer->set("heigh", "60");
            hbox->appendChild(hspacer);

            // Add more button
            ButtonElement *more = new ButtonElement(hbox);
            more->set("width", "150");
            more->set("height", "60");
            more->set("fgcolor", "#000000");
            more->set("bgcolor", "#878787");
            more->setInnerText("More\0");
            hbox->appendChild(more);

        }
        void WhatsNewView::navigate(string uri) {

        }
        WhatsNewView::~WhatsNewView()
        {
            //dtor
        }
    }
}
