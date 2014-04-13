#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H
#include "FontStyle.h"
#include "Color.h"
#include "Image.h"
namespace spider {
    class GraphicsContext {
	private:
		spider_position origo;
		FontStyle *fontStyle;

	public:

		virtual void drawLine(int x, int y, int x2, int y2, Color *color) {}
		virtual void drawRectangle(int x, int y, int w, int h, Color *color) {}
		virtual void fillRectangle(int x, int y, int w, int h, Color *color) {}
		virtual void drawImage(Image *image, int x, int y, int w, int h) {}
		virtual void drawControl(int x, int y, int w, int h, char *name) {}
		virtual void drawString(string *text, FontStyle *fs, Color *color, int x, int y, int w, int h) {}
		void setFontStyle(spider::FontStyle *fs) {
			this->fontStyle = fs;
		}
		FontStyle *getFontStyle() {
			return this->fontStyle;
		}

		virtual void setOrigo(const int& x, const int& y);
	};
}
#endif // GRAPHICSCONTEXT_H
