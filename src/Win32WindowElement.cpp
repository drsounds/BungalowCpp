#include <Windows.h>
#include "Win32WindowElement.h"
#include "Win32GraphicsContext.h"
namespace spider {
    void Win32WindowElement::Draw(GraphicsContext *graphics) {
        std::vector<Node *> *elements = this->getChildNodes();
        for (std::vector<Node *>::iterator it = elements->begin(); it != elements->end(); ++it) {
            Node *node = (Node *)*it;
            Element *elm = static_cast<Element *>(node);
            if (elm->isVisible())
                elm->Draw(0, 0, graphics);
        }
    }
    void Win32WindowElement::invalidateRegion(rectangle rect) {

        Win32GraphicsContext *gc = new Win32GraphicsContext(this->hWnd, NULL);
        gc->invalidateRegion(rect);
        SendMessage(this->hWnd, WM_PAINT, NULL, NULL);
        delete gc;
    }
    Win32WindowElement::Win32WindowElement() {

    }
    Win32WindowElement::Win32WindowElement(HDC hdc) {
        this->memHDC = hdc;
    }
    GraphicsContext *Win32WindowElement::createGraphics() {
        return new Win32GraphicsContext(this->hWnd, NULL);
    }
    void Win32WindowElement::pack() {

        RECT clientRect;
        GetWindowRect(this->getHandle(),&clientRect);
        for (vector<Node *>::iterator it = this->getChildNodes()->begin(); it != this->getChildNodes()->end(); ++it) {
            Element *elm = (Element *)static_cast<Node *>(*it);
            elm->setX(0);
            elm->setY(0);
            int width = clientRect.right - clientRect.left;
            int height = clientRect.bottom - clientRect.top;
            elm->setWidth(width);
            elm->setHeight(height);
            elm->pack();
        }
    }

    void sample_click(spider::Element *elm, void *data) {
        MessageBox(((Win32WindowElement *)elm->getWindowNode())->getHandle(), (LPCSTR)"Test",(LPCSTR)L"A", 0);
    }
    void Win32WindowElement::SampleLayout() {
        this->set("bgcolor", "#474747");
        this->setWindowElement(this);
        this->mainWindow = new MainWindowElement(this);
        this->mainWindow->setWindowElement((WindowElement *)this);
        this->mainWindow->setVisible(true);
        this->mainWindow->layout();
        this->appendChild(mainWindow);
    }
}
/*  This function is called by the Windows function DispatchMessage()  */
