#ifndef URI_H
#define URI_H
#include "libspider.h"
namespace spider {
    class Uri {
	private:
		char *protocol;
		char *entity;
		char *id;
		char *uri;

		vector<char *> *fragments;
	public:
		Uri(char *uri);
		char *getUri() {
            return this->uri;
		}
		~Uri();
	};
}

#endif // URI_H
