#include "MainWindowElement.h"
namespace spider {
MainWindowElement::MainWindowElement()
{

}
MainWindowElement::MainWindowElement(Element *parent) : VBoxElement(parent)
{

    spider::HBoxElement *header = new spider::HBoxElement();
	header->set("bgcolor", "#363636");
	header->set("height", "56");
	header->getPadding()->top = 3;
	header->getPadding()->left = 3;
	header->getPadding()->bottom = 3;
	header->getPadding()->right =  3;
	this->appendChild(header);




	// Add header children

	spider::HBoxElement *body = new spider::HBoxElement();
	body->set("bgcolor", "#474747");
	body->set("flex", "1");
	body->set("height", "100");
	this->appendChild(body);

		// Inside body
	spider::VBoxElement *sidebar = new spider::VBoxElement();
	sidebar->set("width", "220");
	sidebar->set("bgcolor", "#474747");
	body->appendChild(sidebar);

	// Add viewstack

	spider::ViewStackElement *viewStack = new spider::ViewStackElement(body);
    viewStack->set("bgcolor", "#373737");
    body->appendChild(viewStack);
    viewStack->set("flex", "1");
	spider::HBoxElement *footer = new spider::HBoxElement();
	footer->set("bgcolor", "#444444");
	footer->set("height", "56");
	this->appendChild(footer);
	// Add header buttons
	spider::ButtonElement *btn1 = new spider::ButtonElement();
	btn1->setWidth(128);
	btn1->setId(new string("id"));
//	btn1->addEventListener(string("click"), (spider::s_event)sample_click);
	header->appendChild(btn1);

	this->pack();
}

MainWindowElement::~MainWindowElement()
{
    //dtor
}
}
