#ifndef MAINWINDOWELEMENT_H
#define MAINWINDOWELEMENT_H
#include "VBoxElement.h"
#include "HBoxElement.h"
#include "ViewStackElement.h"
#include "ButtonElement.h"
#include "TreeViewElement.h"
namespace spider {
class MainWindowElement : public VBoxElement
{
    public:
        MainWindowElement();
        MainWindowElement(Element *parent);
        virtual ~MainWindowElement();
        void navigate(string uri);
    protected:
    private:
        ViewStackElement *viewStack;
        TreeViewElement *treeView;


};
}
#include "libspider.h"

#endif // MAINWINDOWELEMENT_H
