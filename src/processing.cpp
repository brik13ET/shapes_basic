/*
 * processing.cpp
 *
 *  Created on: 25 окт. 2021 г.
 *      Author: user0
 */
#include <shapes.h>
#include <processing.h>

struct TypeHolder
{
	Shape* S;
	enum
	{
		Circle,
		Rectangle,
		Triangle
	} Type;
};

void Swap	(TypeHolder &a, TypeHolder &b)
{
	TypeHolder _tmp = a;
	a = b;
	b = _tmp;
}

double GetValue(Shape* elem, char elem_char)
{
	double ret;
	switch(elem_char)
	{
	case 'c':
		ret = ((Circle*)elem)->GetArea();
		break;
	case 'r':
		ret = ((Rectangle*)elem)->GetArea();
		break;
	case 't':
		ret = ((Triangle*)elem)->GetArea();
		break;
	default:
		ret = -1;
	}
	return ret;
}

double GetValue(TypeHolder t)
{
	double ret;
	switch(t.Type)
	{
	case TypeHolder::Circle:
		ret = GetValue(t.S, 'c');
		break;
	case TypeHolder::Rectangle:
		ret = GetValue(t.S, 'r');
		break;
	case TypeHolder::Triangle:
		ret = GetValue(t.S, 't');
		break;
	}
	return ret;

}


TypeHolder* BinarySearchInstanse(TypeHolder* beg, TypeHolder* end, double key)
{
	if (end <= beg)
		return (key >= GetValue(beg[0]) ? beg + 1 : beg);

	TypeHolder* mid = beg + (end - beg) / 2 ;
	if (key == GetValue(mid[0]))
		return mid + 1;
	if (key > GetValue(mid[0]))
		return BinarySearchInstanse(mid + 1, end, key);
	// if key < GetValue(*mid)
	return BinarySearchInstanse(beg, mid - 1, key);
}

void	InsertionSort(TypeHolder* beg, TypeHolder* end)
{
	TypeHolder* cur = beg;
	while (cur <= end)
	{
		TypeHolder* n_pos = BinarySearchInstanse(beg, cur, GetValue(cur[0]));
		Swap(n_pos[0], cur[0]);
		cur++;
	}
}

void	Sort	(Shape** shape_arr, int shape_count, char* types_string)
{
	TypeHolder* cont = new TypeHolder[shape_count];
	for(int i = 0; i < shape_count; i++)
	{
		cont[i].S = shape_arr[i];
		switch(types_string[i])
		{
		case 'c':
			cont[i].Type = TypeHolder::Circle;
			break;
		case 'r':
			cont[i].Type = TypeHolder::Rectangle;
			break;
		case 't':
			cont[i].Type = TypeHolder::Triangle;
			break;
		}
	}
	InsertionSort(cont, cont + shape_count - 1);
	for(int i = 0; i < shape_count; i++)
	{
		shape_arr[i] = cont[i].S;
	}
	delete cont;
}


