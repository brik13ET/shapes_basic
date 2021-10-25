#include "file_import.h"
#include "shapes.h"

Shape**	ReadShapes	(std::istream &s, char* &ptr_shape_types, int &shape_count)
{
	char	shape_char;
	shape_count = 0;
	while (!s.eof())
	{
		shape_char = 0;
		s >> shape_char;

		switch(shape_char)
		{
			case 'c' :
			case 'r' :
			case 't' :
				shape_count++;
				break;
			default:
				std::cout << "Error: undefined shape. Skip \'" << shape_char << "\'" << '\n';
		}
		s.ignore(100, '\n');
	}
	Shape** ret = new Shape*[shape_count];
	ptr_shape_types = new char[shape_count + 1];
	s.seekg(0,std::ios::beg);
	s.clear();
	s.sync();
	for (int i = 0; i < shape_count; ++i)
	{
		s >> shape_char;
		ptr_shape_types[i] = shape_char;
		switch(shape_char)
		{
			case 'c' :
			{
				ret[i] = new Circle(0, 0, 0);
				s >> *(Circle*)ret[i];
			}
			break;
			case 'r' :
			{
				ret[i] = new Rectangle(0, 0, 0, 0);
				s >> *(Rectangle*)ret[i];
			}
			break;
			case 't' :
			{
				ret[i] = new Triangle(0, 0, 0, 0, 0, 0);
				s >> *(Triangle*)ret[i];
			}
			break;
			default:
				s.ignore(100, '\n');
				--i;
		}	
	}
	ptr_shape_types[shape_count] = 0;
	return ret;
}

void	WriteShapes	(std::ostream &s, char* shape_types, Shape** shapes_array, int shapes_count)
{
	for (int i = 0; i < shapes_count; ++i)
	{
		s << shape_types[i] << '\t';
		switch(shape_types[i])
		{
			case 'c' :
			{
				s << *((Circle*)shapes_array[i]) << '\n';
			}
			break;
			case 'r' :
			{
				s << *((Rectangle*)shapes_array[i]) << '\n';
			}
			break;
			case 't' :
			{
				s << *((Triangle*)shapes_array[i]) << '\n';
				
			}
			break;
			default:
				--i;
		}	
	}
}
