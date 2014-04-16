#ifndef PLAYQUEUEVIEW_H
#define PLAYQUEUEVIEW_H

#include "ViewElement.h"
namespace spider {
    namespace views {
        class PlayQueueView : public ViewElement
        {
            public:
                PlayQueueView();
                PlayQueueView(Element *parent);
                void navigate(string uri);
                bool acceptsUri(string uri);
                virtual ~PlayQueueView();
            protected:
            private:
        };
    }
}


#endif // PLAYQUEUEVIEW_H
