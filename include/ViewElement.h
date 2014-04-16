#ifndef VIEWELEMENT_H
#define VIEWELEMENT_H
#include "FlowElement.h"
#include "Uri.h"
namespace spider {
    class ViewElement : public FlowElement
    {
        public:
            ViewElement();
            ViewElement(Element *parent);
            virtual ~ViewElement();
            virtual void navigate(string uri);
        protected:
        private:
    };
}
#endif // VIEWELEMENT_H
