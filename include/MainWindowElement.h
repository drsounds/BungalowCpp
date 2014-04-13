#ifndef MAINWINDOWELEMENT_H
#define MAINWINDOWELEMENT_H
#include "VBoxElement.h"
#include "HBoxElement.h"
#include "ViewStackElement.h"
#include "ButtonElement.h"
namespace spider {
class MainWindowElement : public VBoxElement
{
    public:
        MainWindowElement();
        MainWindowElement(Element *parent);
        virtual ~MainWindowElement();
    protected:
    private:
};
}
#include "libspider.h"

#endif // MAINWINDOWELEMENT_H
