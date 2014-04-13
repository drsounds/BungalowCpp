#ifndef SPOYLER_H_INCLUDED
#define SPOYLER_H_INCLUDED
#include <vector>
using namespace std;
namespace Spider {
    class Element;
    class GraphicsContext;
    class Color;
}

namespace Spider {
    struct sp_bounds {
        int x;
        int y;
        int width;
        int height;
    };
class Element {
private:
    vector<Element *> *mChildren;
    sp_bounds *bounds;
    Element *mParent;
public:
    Element *parent() {
        return this->mParent;
    }
    Element() {
        this->mChildren = new vector<Element *>;
    }
    ~Element() {
        delete mChildren;
        delete bounds;
    }
    Element(Element *parent) {
        this->mParent = parent;
    }
    vector<Element *> *children() {
        return this->mChildren;
    }
    int getWidth() {
        return this->bounds->width;
    }
    int getHeight() {
        return this->bounds->height;
    }
    int getX() {
        return this->bounds->x;
    }
    int getY() {
        return this->bounds->y;
    }
    void setX(int x) {
        this->bounds->x = x;
    }
    void setY(int y) {
        this->bounds->y = y;
    }
    void setWidth(int width) {
        this->bounds->width = width;
    }
    void setHeight(int height) {
        this->bounds->height = height;
    }

    /**
     * Pack children
     * @return {void}
     **/
    virtual void packChildren() {

    }

    /**
     * Paints the element
     * @param {GraphicsContext} g
     * @return {void}
     **/
    virtual void paint(GraphicsContext *g) { }
};
    class GraphicsContext {
        virtual void paintRectangle(const sp_bounds& bounds);

    };

    class Color {
        private;
        int r;
        int g;
        int b;
        public:
            int getR() {
                return this->r;
            }
            int getG() {
                return this->g;
            }
            int getB() {
                return this->b;
            }
    };
}

#endif // SPOYLER_H_INCLUDED
