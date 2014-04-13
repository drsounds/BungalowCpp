#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H
#include "libspider.h"
namespace spider {
class MouseEvent {
private:
    int button;
    int x;
    int y;
public:
    int getButton() {
        return this->button;
    }
    int getX() {
        return this->x;
    }
    int getY() {
        return this->y;
    }
    MouseEvent(int btn, int x, int y) {
        this->button = btn;
        this->x = x;
        this->y = y;
    }
};
}
#endif // MOUSEEVENT_H
