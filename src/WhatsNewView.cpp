#include "WhatsNewView.h"
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
             hbox->set("height", "320");
             hbox->set("fgcolor", "#0077ff");

        }
        void WhatsNewView::navigate(string uri) {

        }
        WhatsNewView::~WhatsNewView()
        {
            //dtor
        }
    }
}
