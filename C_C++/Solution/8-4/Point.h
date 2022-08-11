#ifndef POINT_H
#define POINT_H

class Point {
	int x, y;
public:
	Point(int x, int y);
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y);
};
#endif