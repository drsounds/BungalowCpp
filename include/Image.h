#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <Observable.h>
#include <boost/thread.hpp>
using namespace std;
namespace spider {
class Image : public Observable
{
     protected:
        char *imageData;
        char *type;
        string *uri;
        boost::thread *worker;
    public:
        Image(string *uri);
        virtual ~Image();
        void download();
        void downloadImageAsync();

    private:
};
}

#endif // IMAGE_H
