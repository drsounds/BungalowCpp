#ifndef SPTYPE_H
#define SPTYPE_H
#include <string>
using namespace std;
namespace spider {
    class SPType {
    public:
        virtual string getType() {
            return "Undefined";
        }
    };


}
#endif // SPTYPE_H
