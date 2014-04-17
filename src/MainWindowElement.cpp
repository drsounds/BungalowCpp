#include "MainWindowElement.h"
#include "StartView.h"
namespace spider {
    MainWindowElement::MainWindowElement()
    {

    }
    int treeview_itemselected(SPType *sender, EventArgs *e) {
        TreeViewElement *treeView = (TreeViewElement *)sender;
        MainWindowElement *mainWindow = (MainWindowElement *)treeView->getMainWindowElement();
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
        this->setMainWindowElement(this);
        this->setWindowElement(this->getWindowElement());
        this->set("bgcolor", "#373737");
        spider::HBoxElement *header = new spider::HBoxElement(this);
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
        treeView->set("bgcolor", "#575757");
        treeView->set("fgcolor", "#dddddd");
        treeView->set("flex", "1");
        treeView->set("height", "920");
        treeView->set("width", "220");
        sidebar->appendChild(treeView);
        treeView->setWindowElement(this->getWindowElement());
        treeView->setMainWindowElement(this);
        // Add sample elements
        TreeItem *item = new TreeItem(new Uri("spoyler:internal:start"));

        item->setSelected(false);
        TreeItem *item2 = new TreeItem(new Uri("spoyler:internal:history"));

        item2->setSelected(false);
        treeView->addEventListener("itemselected", treeview_itemselected);
        treeView->addItem(item);
        treeView->addItem(item2);

        // Add viewstack





        this->viewStack = new spider::ViewStackElement(body);
        viewStack->set("bgcolor", "#373737");
        body->appendChild(viewStack);
        viewStack->set("flex", "1");

        viewStack->appendChild(new spider::views::StartView(this));
        spider::HBoxElement *footer = new spider::HBoxElement(this);
        footer->set("bgcolor", "#444444");
        footer->set("height", "86");
        this->appendChild(footer);
        // Add header buttons


        this->pack();
    }
    ViewStackElement *MainWindowElement::getViewStack() {
        return this->viewStack;
    }
    MainWindowElement::~MainWindowElement()
    {
        //dtor
    }
}
