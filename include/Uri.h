#ifndef URI_H
#define URI_H
#include "libspider.h"
namespace spider {
    class Uri {
	private:
		string *protocol;
		string *entity;
		string *id;

		vector<string *> *fragments;
	public:
		Uri(const string& uri);
		~Uri();
	};
}

#endif // URI_H
