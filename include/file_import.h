#ifndef FILE_IMPORT
#define FILE_IMPORT

#include "shapes.h"
#include <iostream>

Shape**	ReadShapes	(std::istream &s, char*	&ptr_shape_types, int &shape_count);
void	WriteShapes	(std::ostream &s, char* shape_types, Shape** shapes_array, int shapes_count);

#endif
