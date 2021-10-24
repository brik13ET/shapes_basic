#ifndef HEADER_H
#define HEADER_H

const double PI = 3.1415926535897931;

class Position
{
public:
	int x, y;
	Position(int X, int Y, int Z) : x(X), y(Y) { };
	Position(Position pos) : x(pos.x), y(pos.y) { };
	~Position() { };
};

enum Color
{
	Red,
	Orange,
	Yellow,
	Green,
	light_blue,
	blue,
	purple
};

class Shape
{
public:
	virtual double GetArea() = 0;
};

class Circle : Shape
{
public:
	Position Position;
	Color Fill;
	int Radius;
	Circle(int x, int y, int radius) : Position(x, y), Radius(radius) { }
	Circle(Position pos, int radius) : Position(pos), Radius(radius) { }
	~Circle() { }
};

class Rectangle : Shape
{
private:
public:
	Position vertex_1, vertex_2;
	Color Fill;
	Rectangle(int x1, int x2, int y1, int y2) : vertex_1(x1, y1), vertex_2(x2, y2)  { }
	Rectangle(int x1, int y1, int width, int height) : vertex_1(x1, y1), vertex_2(x1 + width, y1 + height)  { }
	Rectangle(Position v1, Position v2) : vertex_1(v1), vertex_2(v2)  { }
	~Rectangle();
};

class Triangle : Shape
{
public:
	Position vertex_1, vertex_2, vertex_3;
	Color Fill;
	Rectangle(int x1, int x2, int y1, int y2, int x3, int y3) : vertex_1(x1, y1), vertex_2(x2, y2), vertex_3(x3, y3)  { }
	Rectangle(Position v1, Position v2, Position v3) : vertex_1(v1), vertex_2(v2), vertex_3(v3)  { }
	~Triangle()  { }
};

#endif