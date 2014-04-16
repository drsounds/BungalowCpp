#include "MainWindowElement.h"
namespace spider {
    MainWindowElement::MainWindowElement()
    {

    }
    int treeview_itemselected(SPType *sender, EventArgs *e) {
        MainWindowElement *mainWindow = (MainWindowElement *)sender;
        TreeViewEventArgs *args = (TreeViewEventArgs *)e;
        TreeItem *selectedItem = args->getItem();
        Uri *uri = selectedItem->getUri();
        char *uri2 = uri->getUri();
        string uri3 (uri2);
        mainWindow->getViewStack()->navigate(uri3);
        return 0;
    }
    MainWindowElement::MainWindowElement(Element *parent) : VBoxElement(parent)
    {


    }
    void MainWindowElement::layout() {
        spider::HBoxElement *header = new spider::HBoxElement();
        header->set("bgcolor", "#767676");
        header->set("height", "56");
        header->getPadding()->top = 3;
        header->getPadding()->left = 3;
        header->getPadding()->bottom = 3;
        header->getPadding()->right =  3;
        this->appendChild(header);




        // Add header children

        spider::HBoxElement *body = new spider::HBoxElement(this);
        body->set("bgcolor", "#474747");
        body->set("flex", "1");
        body->set("height", "100");
        this->appendChild(body);

            // Inside body
        spider::VBoxElement *sidebar = new spider::VBoxElement(body);
        sidebar->set("width", "220");
        sidebar->set("bgcolor", "#474747");
        body->appendChild(sidebar);

        // Add TreeView
        this->treeView = new TreeViewElement(sidebar);
        treeView->set("bgcolor", "#666666");
        treeView->set("fgcolor", "#dddddd");
        treeView->set("flex", "1");
        treeView->set("height", "920");
        treeView->set("width", "220");
        sidebar->appendChild(treeView);
        treeView->setWindowElement(this->getWindowElement());

        // Add sample elements
        for (int i = 0; i < 3; i++) {
            TreeItem *item = new TreeItem(new Uri("spoyler:internal:start"));

            item->setSelected(i == 0);
            treeView->addItem(item);
        }
        treeView->addEventListener("itemselected", treeview_itemselected);
        // Add viewstack





        this->viewStack = new spider::ViewStackElement(body);
        viewStack->set("bgcolor", "#373737");
        body->appendChild(viewStack);
        viewStack->set("flex", "1");
        spider::HBoxElement *footer = new spider::HBoxElement();
        footer->set("bgcolor", "#444444");
        footer->set("height", "86");
        this->appendChild(footer);
        // Add header buttons


        this->pack();
    }

    MainWindowElement::~MainWindowElement()
    {
        //dtor
    }
}
