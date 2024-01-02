#include"file_exporter.h"

void Exportovtk(int nodes_number, Node* nodes, int elements_number, Element* elements)
{
	std:: fstream out;
	out.open("wyniki.vtk", std::ios::out);
	out << "# vtk DataFile Version 2.0" << std::endl;
	out << "Unstructured Grid Example" << std::endl;
	out << "ASCII" << std::endl;
	out << "DATASET UNSTRUCTURED_GRID" << std::endl;
	out << std::endl;
	out << "POINTS "<<nodes_number<<" float" << std::endl;
	for (int i = 0; i < nodes_number; i++)
	{
		out << nodes[i].get_x() << " " << nodes[i].get_y() << " " << "0" << std::endl;
	}
	out << "CELLS " << elements_number << "  45" << std::endl;
	for (int i = 0; i < elements_number; i++)
	{
		out << "4 ";
			for (int j = 0; j < 4; j++)
			{
				out << elements[i].nodes[j].get_number() << " ";
			}
			out << std::endl;
	}
	out << "CELL_TYPES 9" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		out << "9" << std::endl;
	}
	out << "POINT_DATA 16" << std::endl;
	out << "SCALARS Temp float 1" << std::endl;
	out << "LOOKUP_TABLE default" << std::endl;

}