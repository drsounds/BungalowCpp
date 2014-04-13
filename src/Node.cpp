#include "Node.h"
namespace spider {



    Node::Node() {
        if(this->window == NULL)
            this->window = this;
    }
    Node* Node::getParent() {
        return this->parent;
    }

    void Node::setParent(Node *elm) {
        this->parent = (elm);
    }
    std::string Node::get(const std::string& title) {
        return (*this->attributes)[title];
    }
    void* Node::getObject(const std::string& title) {
        return (*this->properties)[title];
    }
    void Node::set(const std::string& title, const std::string& val) {
        int n = 0;
        try {
            int n = boost::lexical_cast<int>(val);

            (*this->properties)[title] = (void *)n;
        } catch (exception e) {
            (*this->properties)[title] = (void *)&val;
        }

        if(val.find("#") == 0) {
            Color *c =new Color(val);;
            (*this->properties)[title] = (void *)c;
        }
    }

    void Node::appendChild(spider::Node *child) {
        this->getChildNodes()->push_back(child);
        child->setParent(this);
        child->window = this->getWindowNode();
    }
    Node *getElementById(string *id) {
        return NULL;
    }
    Node *Node::getWindowNode() {
        return this->window;
    }








}
