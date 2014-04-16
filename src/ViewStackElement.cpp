#include "ViewStackElement.h"
#include "WhatsNewView.h"
#include <regex>
#include <list>
namespace spider {
    ViewStackElement::ViewStackElement()
    : BoxElement::BoxElement() {
         this->history = new std::stack<string *>;
         this->future = new std::stack<string *>;
    }
    ViewStackElement::ViewStackElement(Element *parent)
     : BoxElement::BoxElement(parent) {
         this->setParent(this);
         this->history = new std::stack<string *>;
         this->future = new std::stack<string *>;
        list<Node *> *children = this->getChildNodes();
    }
    /**
     * Main navigation handler inside Spotify
     **/
    void ViewStackElement::navigate(string uri) {
        // TODO add navigation handler
        ViewElement *view = NULL;
        std::stack<string *> *history = this->history;
        ViewStackElement *th = this;
        // Hide all views

        if (std::regex_match(uri.c_str(), std::regex("spoyler:internal:start"))) {

            // Show What's new view
            view = new views::WhatsNewView((Element *)this);

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:playqueue"))) {

            // Show playqueue view and switch to the queue tab

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:history"))) {

            // Show playqueue view and switch to the history tab

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:config"))) {

            // Show Spotify config page

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:artist:(.*)"))) {

            // Load artist view and navigate to apporiate artist

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:album:(.*)"))) {

            // Load album view and navigate to apporiate artist

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:user:(.*):playlist:(.*)"))) {

            // Load user playlists view

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:internal:radio"))) {

            // Load radio view

        } else if (std::regex_match(uri.c_str(), std::regex("^spoyler:config2"))) {

            // Show the extended config2 dialog

        } else {

            // Show error message (The URI could not be found)
            return;
        }
        list<Node *> *children = this->getChildNodes();
        if (view != NULL) {
            this->appendChild(view);
            view->navigate(uri);
        }
        this->invalidate();

    }



}
