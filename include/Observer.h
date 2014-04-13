#ifndef OBSERVER_H
#define OBSERVER_H
#include "libspider.h"
namespace spider {
class Observer {
private:
    string _event;
    s_event callback;
public:
    string getEvent() {
        return this->_event;
    }
    s_event getCallback() {
        return this->callback;
    }
    Observer(string _event, s_event callback) {
        this->callback = callback;
        this->_event = _event;
    }
    ~Observer() {
    }
};
}
#endif // OBSERVER_H
