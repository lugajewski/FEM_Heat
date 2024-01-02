#include"input_loader.h"

class input_loader
{
	global_data gd;
	node* nd;
	element* el;
	grid gr;
public:
	input_loader(std::string file)
	{
		nd = new node[16];
		el = new element[9];
		std::fstream in;
		in.open(file, std::ios::in);
		std::string trash;
		in >> trash;
		in >> gd.simulation_time;
		in >> trash;
		in >> gd.simulation_step_time;
		in >> trash;
		in >> gd.conductivity;
		in >> trash;
		in >> gd.alfa;
		in >> trash;
		in >> gd.tot;
		in >> trash;
		in >> gd.initial_temp;
		in >> trash;
		in >> gd.density;
		in >> trash;
		in >> gd.specific_heat;
		in >> trash;
		in >> gd.nodes_number;
		in >> trash;
		in >> gd.elements_number;
		in >> trash;
		for (int i = 0; i < 16; i++)
		{
			in >> nd[i].number;
			in >> nd[i].x;
			in >> nd[i].y;
		}
		in >> trash;
		in >> trash;
		for (int i = 0; i < 9; i++)
		{
			in >> el[i].number;
			for (int j = 0; j < 4; j++)
			{
				in >> el[i].nodes[j];
			}
		}
		in >> trash;
		in.close();
	}
	void get_nodes(node* pointer, int number)
	{
		for (int i = 0; i < number; i++)
		{
			pointer[i] = nd[i];
		}
	}
	void get_elements(element* pointer, int number)
	{
		for (int i = 0; i < number; i++)
		{
			pointer[i] = el[i];
		}
	}
	void get_grid(grid* pointer)
	{
		*pointer = gr;
	}
	void get_global_data(global_data* pointer)
	{
		*pointer = gd;
	}
	void get_all(node* p1, int number_of_nodes, element* p2, int number_of_elements, grid* p3, global_data* p4)
	{
		get_nodes(p1,number_of_nodes);
		get_elements(p2,number_of_elements);
		get_grid(p3);
		get_global_data(p4);
	}
	void dest()
	{
		delete[] nd;
		delete[] el;
	}
};
