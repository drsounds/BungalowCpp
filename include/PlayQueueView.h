#ifndef PLAYQUEUEVIEW_H
#define PLAYQUEUEVIEW_H

#include "ViewElement.h"
namespace spider : public ViewElement {
class PlayQueueView
{
    public:
        PlayQueueView();
        PlayQueueView(Element *parent);
        void navigate(string uri);
        virtual ~PlayQueueView();
    protected:
    private:
};
}

#endif // PLAYQUEUEVIEW_H
