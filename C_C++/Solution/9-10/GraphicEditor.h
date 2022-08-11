#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H
#include "Shape.h"
class GraphicEditor {
	Shape *pStart = nullptr;
	Shape *pLast = nullptr;
	int nNum = 0;
public:
	GraphicEditor();
	void attach(Shape *p);
	void detach(int index);
	void seeAll();
	void endThis();
};
#endif