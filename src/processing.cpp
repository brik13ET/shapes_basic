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


int BinarySearch(TypeHolder a[], TypeHolder item, int low, int high)
{
    if (high <= low)
        return (GetValue(item) > GetValue(a[low])) ?
                (low + 1) : low;

    int mid = (low + high) / 2;

    if (GetValue(item) == GetValue(a[mid]))
        return mid + 1;

    if (GetValue(item) > GetValue(a[mid]))
        return BinarySearch(a, item, mid + 1, high);
    return BinarySearch(a, item, low, mid - 1);
}

void InsertionSort(TypeHolder a[], int n)
{
    int i, loc, j;
    TypeHolder selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected should be inseretd
        loc = BinarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void Revert(TypeHolder a[], int n)
{
	TypeHolder _tmp;
	for (int i = 0; i < n / 2;i ++)
	{
		Swap(a[i], a[n - i - 1]);
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
	InsertionSort(cont, shape_count);
	Revert(cont, shape_count);
	for(int i = 0; i < shape_count; i++)
	{
		shape_arr[i] = cont[i].S;
	}
	delete cont;
}


