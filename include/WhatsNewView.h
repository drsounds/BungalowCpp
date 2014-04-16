#ifndef WHATSNEWVIEW_H
#define WHATSNEWVIEW_H
#include "ViewElement.h"
namespace spider {
    namespace views {
        class WhatsNewView : public ViewElement
        {
            public:
                WhatsNewView();
                WhatsNewView(Element *parent);
                virtual ~WhatsNewView();
                void navigate(string uri);
            protected:
            private:
        };
    }
}

#endif // WHATSNEWVIEW_H
