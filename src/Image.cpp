#include "Image.h"
namespace spider {
Image::Image(string *uri)
{
    //ctor
    this->uri;
}
void Image::download() {
    string uri = *this->uri;
    if (string->find("http") == 0) {
        // Download image async

    }
}

void Image::downloadImageAsync() {

    this->worker = new boost::thread (&Image::downloader);
}

Image::~Image()
{
    delete this->uri;
    //dtor
}
}
