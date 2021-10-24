#include <cmath>
#include "header.h"

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
	return 2 * PI * this->Radius
}

double Rectangle::GetArea()
{
	Position tmp = new Position(this->vertex_1.x, this->vertex_2.y);
	double l1 = Length(this->vertex_1, tmp);
	double l2 = Length(this->vertex_2, tmp);
	return std::abs(l1 * l2);
}

double Triangle::GetArea()
{
	Position tmp = new Position(this->vertex_2.x + (this->vertex_1.x - this->vertex_2.x) / 2, this->vertex_2.y + (this->vertex_1.y - this->vertex_2.y) / 2);
	double l1 = Length(this->vertex_1, this->vertex_2);
	double l2 = Length(this->vertex_3, tmp);
	return 0.5 * (l1 * l2);
}
