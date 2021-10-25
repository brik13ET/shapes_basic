#include <iostream>
#include <cmath>
#include "shapes.h"

Position::Position	(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

Position::Position	(Position& P)
{
	this->x = P.x;
	this->y = P.y;
}

Circle::Circle	(int X, int Y, int R)
{
	this->Location = new Position(X, Y);
	this->Radius = R;
	Fill = Color::Red;
}

Circle::Circle	(Position P, int R)
{
	this->Location = new Position(P);
	this->Radius = R;
	Fill = Color::Red;
}

Rectangle::Rectangle	(int X1, int Y1, int X2, int Y2)
{
	this->vertex_1 = new Position(X1, Y1);
	this->vertex_2 = new Position(X2, Y2);
	Fill = Color::Red;
}

Rectangle::Rectangle	(Position P1, Position P2)
{
	this->vertex_1 = new Position(P1);
	this->vertex_2 = new Position(P2);
	Fill = Color::Red;
}

Triangle::Triangle	(int X1, int Y1, int X2, int Y2, int X3, int Y3)
{
	this->vertex_1 = new Position(X1, Y1);
	this->vertex_2 = new Position(X2, Y2);
	this->vertex_3 = new Position(X3, Y3);
	Fill = Color::Red;
}

Triangle::Triangle	(Position P1, Position P2, Position P3)
{
	this->vertex_1 = new Position(P1);
	this->vertex_2 = new Position(P2);
	this->vertex_3 = new Position(P3);
	Fill = Color::Red;
}

Position::~Position	() { }
Circle::~Circle	()
{
	delete Location;
}

Rectangle::~Rectangle	()
{
	delete vertex_1;
	delete vertex_2;
}

Triangle::~Triangle	()
{
	delete vertex_1;
	delete vertex_2;
	delete vertex_3;
}


double Length(Position p1, Position p2)
{
	int a_x = p1.x,
		a_y = p1.y,
		b_x = p2.x,
		b_y = p2.y,
		x = b_x - a_x,
		y = b_y - a_y;
	return std::sqrt(x*x + y*y);
}

double Circle::GetArea()
{
	return 2 * PI * this->Radius;
}

double Rectangle::GetArea()
{
	Position* tmp = new Position(this->vertex_1->x, this->vertex_2->y);
	double l1 = Length(*this->vertex_1, *tmp);
	double l2 = Length(*this->vertex_2, *tmp);
	return std::abs(l1 * l2);
}

double Triangle::GetArea()
{
	double l1 = Length(*vertex_1, *vertex_2);
	double l2 = Length(*vertex_1, *vertex_3);
	double l3 = Length(*vertex_2, *vertex_3);
	double P = l1 + l2 + l3, p = P / 2;
	return  std::sqrt(p * (p - l1) * (p - l2) * (p - l3));
}


std::ostream& operator<<(std::ostream& out, Position p)
{
	out << p.x << '\t' << p.y;
	return out;
}

std::istream& operator>>(std::istream& in, Position &p)
{
	in >> p.x >> p.y;
	return in;
}

std::ostream& operator<<(std::ostream& out, Circle s)
{
	out	<< *s.Location << '\t'
		<< s.Radius << '\t'
		<< s.Fill;
	return out;
}

std::ostream& operator<<(std::ostream& out, Rectangle s)
{
	out << *s.vertex_1 << '\t'
		<< *s.vertex_2 << '\t'
		<< s.Fill;
	return out;
}

std::ostream& operator<<(std::ostream& out, Triangle s)
{
	out << *s.vertex_1 << '\t'
		<< *s.vertex_2 << '\t'
		<< *s.vertex_3 << '\t'
		<< s.Fill;
	return out;
}

std::istream& operator>>(std::istream &in, Circle &s)
{
	in >> *s.Location >> s.Radius >> s.Fill;
	return in;
}

std::istream& operator>>(std::istream &in, Rectangle &s)
{
	in >> *s.vertex_1 >> *s.vertex_2 >> s.Fill;
	return in;
}

std::istream& operator>>(std::istream &in, Triangle &s)
{
	in >> *s.vertex_1 >> *s.vertex_2 >> *s.vertex_3 >> s.Fill;
	return in;
}

std::ostream& operator<<(std::ostream& out, Color c)
{
	out << (int)c;
	return out;
}

std::istream& operator>>(std::istream& in, Color &c)
{
	int _c;
	in >> _c;
	if (_c >= Color::Error)
		c = Color::Error;
	else
		c = (Color)_c;
	return in;
}
