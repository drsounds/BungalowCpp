#ifndef BOXELEMENT_H
#define BOXELEMENT_H
#include "Element.h"
namespace spider {
	class BoxElement : public Element {

	public:
	    BoxElement(Element *parent) : Element(parent) {
	    }
		BoxElement();
		~BoxElement();
		void pack();

	};
}
#endif // BOXELEMENT_H
