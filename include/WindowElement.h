#ifndef H_SPIDER_WINDOW_ELEMENT
#define H_SPIDER_WINDOW_ELEMENT
#include "VBoxElement.h"

namespace spider {

	class WindowElement : public VBoxElement {
	public:
		void Draw(spider::GraphicsContext *gs);
		WindowElement();
		virtual spider::GraphicsContext *createGraphics();
		virtual void invalidateRegion(rectangle rect) {}

	};

};

#endif
