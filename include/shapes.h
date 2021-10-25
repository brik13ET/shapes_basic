#ifndef SHAPES_H
#define SHAPES_H

#include <ios>
const double PI = 3.1415926535897931;

class Position
{
public:
	int x, y;
	Position(int X, int Y);
	Position(Position& pos);
	~Position();
};


enum Color
{
	Red	= 0,
	Orange	= 1,
	Yellow	= 2,
	Green	= 3,
	LBlue	= 4,
	Blue	= 5,
	Purple	= 6,
	Error
};

class Shape
{
public:
	virtual double GetArea() = 0;
};

class Circle : public Shape
{
public:
	Position* Location;
	Color Fill;
	int Radius;
	Circle(int x, int y, int radius);
	Circle(Position pos, int radius);
	double GetArea();
	~Circle();
};

class Rectangle : public Shape
{
public:
	Position *vertex_1, *vertex_2;
	Color Fill;
	Rectangle(int x1, int x2, int y1, int y2);
	Rectangle(Position v1, Position v2);
	double GetArea();
	~Rectangle();
};


class Triangle : public Shape
{
public:
	Position *vertex_1, *vertex_2, *vertex_3;
	Color Fill;
	Triangle(int x1, int x2, int y1, int y2, int x3, int y3);
	Triangle(Position v1, Position v2, Position v3);
	double GetArea();
	~Triangle();
};

std::ostream& operator<<	(std::ostream& out, Position p);
std::ostream& operator<<	(std::ostream& out,	Color c);
std::ostream& operator<<	(std::ostream& out, Circle s);
std::ostream& operator<<	(std::ostream& out, Rectangle r);
std::ostream& operator<<	(std::ostream& out, Triangle s);

std::istream& operator>>	(std::istream& in, Position &p);
std::istream& operator>>	(std::istream& in,	Color &c);
std::istream& operator>>	(std::istream& in, Circle &s);
std::istream& operator>>	(std::istream& in, Rectangle &r);
std::istream& operator>>	(std::istream& in, Triangle &s);

#endif
