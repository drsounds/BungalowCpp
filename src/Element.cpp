#include "Element.h"
namespace spider {

void Element::mouseDown(int& mouseButton, int& x, int& y) {
	MouseEventArgs *me = new MouseEventArgs(mouseButton, x, y);

	this->notify(string("mousedown"), this, me);
}

void Element::mouseClick(int& mouseButton, int& x, int& y) {
	MouseEventArgs *me = new MouseEventArgs(mouseButton, x, y);

	this->notify(string("click"), this, me);
}
void Element::click(int mouseButton, int x, int y) {
	this->mouseClick(mouseButton, x, y);
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);

		if(x > elm->x && x < elm->x + elm->getWidth() &&
			y > elm->y && y < elm->y + elm->getHeight()) {

			elm->click(mouseButton, elm->x + x , elm->y + y);
		}
	}
}
void Element::mousedown(int mouseButton, int x, int y) {
	this->mouseDown(mouseButton, x, y);
	for(vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);

		if(x > elm->x && x < elm->x + elm->getWidth() &&
			y > elm->y && y < elm->y + elm->getHeight()) {

			elm->mousedown(mouseButton, elm->x + x , elm->y + y);
		}
	}
}

Element::Element() {
	this->setScrollable(false);
	this->scrollX = 0;
	this->scrollY = 0;
    this->data = NULL;
    this->visible = true;
	this->observers = new vector<Observer *>();
	this->properties = new map<string, void *>();
	this->attributes = new map<string, string>();
	this->set("bgcolor", "#555555ff");
	this->font = new FontStyle("MS Sans Serif", 11, 1, false, false);
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->width = 0;
	this->height = 0;
	this->margins = new margin();
	this->margins->left = 0;
	this->margins->top = 0;
	this->margins->right= 0;
	this->margins->bottom = 0;
	this->padding = new margin();
	this->padding->left = 0;
	this->padding->top = 0;
	this->padding->right= 0;
	this->padding->bottom = 0;

}
Element::Element(Element *parent) {
	this->setScrollable(false);
	this->scrollX = 0;
	this->scrollY = 0;
    this->data = NULL;
	this->observers = new vector<Observer *>();
	this->setParent(parent);
	this->properties = new map<string, void *>();
	this->attributes = new map<string, string>();
	if (this->getParent() != NULL) {
        this->set("bgcolor", "#474747");
        this->font = parent->font;
	}
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->width = 0;
	this->height = 0;
	this->margins = new margin();
	this->margins->left = 0;
	this->margins->top = 0;
	this->margins->right = 0;
	this->margins->bottom = 0;
	this->padding = new margin();
	this->padding->left = 0;
	this->padding->top = 0;
	this->padding->right = 0;
	this->padding->bottom = 0;

}
margin *Element::getMargins() {
	return this->margins;
}
margin *Element::getPadding() {
	return this->padding;
}
Element::~Element() {

}


int Element::getHeight() {
	return this->height;
};
int Element::getWidth() {
	return this->width;
}
int Element::getX() {
	return this->x;
}
int Element::getY() {
	return this->y;
}
int Element::getZ() {
	return this->z;
}
void Element::setWidth(int w) {
	this->width = w;
}
void Element::setHeight(int h) {
	this->height = h;

}
void Element::setX(int x) {
	this->x = x;
}
void Element::setY(int y) {
	this->y = y;
}
void Element::setZ(int z) {
	this->z = z;
}
void Element::notify(string evt, SPType *sender, EventArgs *data) {
	for(vector<Observer *>::iterator it = this->observers->begin(); it != this->observers->end(); ++it) {
		Observer *observer = static_cast<Observer *>(*it);
		string t = observer->getEvent();
		if(t == (evt)) {
			s_event evt = (observer->getCallback());
			evt(this, data);
		}
	}
}
void Element::addEventListener(string evt, s_event callback) {
    Observer *observer = new Observer(evt, callback);


	this->observers->push_back(observer);
}



void Element::set(const std::string& title, const std::string& val) {
	int n = 0;
	try {
		int n = boost::lexical_cast<int>(val);
		if(title == "width")
			this->setWidth(n);
		if(title == "height")
			this->setHeight(n);
		if(title == "x")
			this->setX(n);
		if(title == "y")
			this->setY(n);


		(*this->properties)[title] = (void *)n;
	} catch (exception e) {
		(*this->properties)[title] = (void *)&val;
	}

	if(val.find("#") == 0) {
		Color *c =new Color(val);;
		(*this->properties)[title] = (void *)c;
	}
}

void Element::setId(char *id) {
	this->id = id;
}
char *Element::getId() {
	return this->id;
}

bool Element::hasAttribute(string attr) {
	map<string, void *>::iterator it = this->properties->find(attr);
	return it != this->properties->end();
}






void *Element::getAttributeObj(string prop) {

		void *t = (void *)(*this->properties)[prop];
	return t;
}
std::vector<Node *> *Node::getChildNodes() {
	return &(this->children);
}
void Element::Draw(int x, int y, GraphicsContext *c) {

	spider_position pos;
	std::vector<Node *> *children = this->getChildNodes();
	x += this->getX();
	y += this->getY();
	int width =  this->getWidth();
	int height = this->getHeight();

	rectangle rect2;
	rect2.x = 0;
	rect2.y = 0;
	rect2.width = width;
	rect2.height = height;

	c->fillRectangle(x, y, width, height, (Color *)this->getAttributeObj("bgcolor"));
	//c->drawRectangle(x, y, this->getWidth(), this->getHeight(), (Color *)this->getAttributeObj("bgcolor"));
	//Color color(255, 0, 0, 255);
    //	c->drawRectangle(0, 0, this->getWidth(), this->getHeight() , &color);
    char *text = this->getInnerText();
    // Draw text
    if (text != NULL)
        c->drawString(this->getInnerText(), new FontStyle("MS Sans Serif", 8, 4, false, false), new Color(255, 255, 255, 255), x, y, 300, 8);

	// adjust for scroll
    x -= this->scrollX;
    y -= this->scrollY;
	for(std::vector<Node *>::iterator it = children->begin(); it != children->end(); ++it) {
		Element *elm = static_cast<Element *>(*it);
		if(elm != NULL) {
			elm->Draw(x, y, c);
		}
	}
	rectangle rect;
	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;

	x += this->scrollX;
    y += this->scrollY;
	x -= this->getX();
	y -= this->getY();
	//c->setOrigo(-x - getX(), -y - getY());
}


char *Element::getInnerText() {
    char *data = this->data;
	return data;
}
void Element::setInnerText(char *data) {
	 this->data = data;
}
}


