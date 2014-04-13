#ifndef H_LIBSPIDER
#define H_LIBSPIDER
#include <map>
#include <string>
#include <list>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#define DEBUG
#define CONTROL_INPUT 1
using namespace std;

namespace spider {
    typedef struct margin {
        int left;
        int top;
        int bottom;
        int right;
    };
    int htmlToColor(string str);
	typedef struct spider_position {
		int x;
		int y;
	};
	typedef struct s_size {
		int width;
		int height;
		int x;
		int y;
		int z;
	};

	typedef int(*s_event)(void *, void *);
}
#endif
