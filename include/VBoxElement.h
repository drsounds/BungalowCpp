#ifndef VBOXELEMENT_H
#define VBOXELEMENT_H
#include "Element.h"
namespace spider {
    class VBoxElement : public Element {

	public:
	    VBoxElement(Element *parent) : Element(parent) {
		}
		VBoxElement();

		void pack();
	};
}
#endif // VBOXELEMENT_H
