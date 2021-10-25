#include <ios>
#include <fstream>
#include <string>

#include <shapes.h>
#include <file_import.h>
#include <processing.h>

int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 3)
	{
		std::cout << "Usage: " << argv[0] << " FIN FOUT \n";
		return -1;
	}

	std::ifstream f_in (argv[1], std::ios_base::in);
	std::ofstream f_out(argv[2], std::ios_base::out);
	char* shape_types;
	int shape_count;
	Shape** ptr_shapes;

	ptr_shapes = ReadShapes(f_in, shape_types, shape_count);

	std::cerr << "Sort()\n";
	Sort(ptr_shapes, shape_count, shape_types);
	std::cerr << "WriteShapes()\n";
	WriteShapes(f_out, shape_types, ptr_shapes, shape_count);

	f_in.close();
	f_out.close();
	std::cerr << "Cleanup\n";

	delete[] ptr_shapes;
	delete[] shape_types;

	return 0;
}
