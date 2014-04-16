#ifndef NODE_H
#define NODE_H
#include "SPType.h"
#include "Color.h"
#include <boost/lexical_cast.hpp>
#include <map>
#include <string>
#include <list>
using namespace std;
namespace spider {

class Node : public SPType {
    map<string, void *> *properties;
    map<string, string *> *attributes;
    Node *pparent;
    Node *window;
    std::list<Node *> *children;
    Node *parent;
public:
    Node();
    void appendChild(Node *child);
    void setChildren(std::list<Node *> *children) {
        this->children = children;
    }

    Node *getElementById(string *id);
    virtual void set(const string& attrib, string *val);
    virtual void set(const string& attrib, const string val);
    string get(const string& attrib);
    void *getObject(const string& attrib);
    string getValue(const string& attrib);
    Node *getParent();

    map<string, string *> *getAttributes() {
        return this->attributes;
    }
    map<string, void *> *getProperties() {
        return this->properties;
    }

    Node *getWindowNode();

    void setParent(Node *parent);
    std::list<Node *> *getChildNodes();
    bool hasAttribute(string attrib);
        string *getAttribute(string title);
    void *getAttributeObj(string title);
    void setAttribute(string attribute, string value);

};
}
#endif // NODE_H
