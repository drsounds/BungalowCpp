#ifndef URI_H
#define URI_H
#include "libspider.h"
namespace spider {
    class Uri {
	private:

		vector<char *> *fragments;
	public:
		char *protocol;
		char *entity;
		char *id;
		char *uri;
		Uri(char *uri);
		char *getUri() {
            return this->uri;
		}
		~Uri();
	};
}

#endif // URI_H
