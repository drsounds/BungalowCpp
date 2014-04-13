#ifndef NODE_H
#define NODE_H
#include "SPType.h"
#include "Color.h"
#include <boost/lexical_cast.hpp>
#include <map>
#include <string>
#include <vector>
using namespace std;
namespace spider {

class Node : public SPType {
    map<string, void *> *properties;
    map<string, string> *attributes;
    Node *pparent;
    Node *window;
    std::vector<Node *> children;
    Node *parent;
public:
    Node();
    void appendChild(Node *child);
    Node *getElementById(string *id);
    void set(const string& attrib, const string& val);
    string get(const string& attrib);
    void *getObject(const string& attrib);
    string getValue(const string& attrib);
    Node *getParent();

    Node *getWindowNode();

    void setParent(Node *parent);
    std::vector<Node *> *getChildNodes();
};
}
#endif // NODE_H
