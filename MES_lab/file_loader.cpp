#pragma once
#include"file_loader.h"

double File_loader::extract_number(std::string string)
{
	std::stringstream line;
	line << string;
	std::string word;
	double number;
	while (!line.eof())
	{
		line >> word;
		if (std::stringstream(word) >> number)
		{
			return number;
		}
		word = "";
	}
	return -1.0;
}
void File_loader::load_data_from_file(std::string file)
{
	std::fstream input;
	input.open(file, std::ios::in);
	std::string buff = "";
	//pobieranie danych
	std::getline(input, buff);
	glo_data.set_simulation_time(extract_number(buff));
	
	std::getline(input, buff);
	glo_data.set_simulation_step_time(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_conductivity(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_alfa(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_tot(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_initial_temp(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_density(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_specific_heat(extract_number(buff));

	std::getline(input, buff);
	glo_data.set_nodes_number((int)extract_number(buff));

	std::getline(input, buff);
	glo_data.set_elements_number((int)extract_number(buff));
	//alokacja wezlow i elementow
	nodes = new Node[glo_data.get_nodes_number()];
	elements = new Element[glo_data.get_elements_number()];
	//czytanie nodow
	std::getline(input, buff);
	int k = glo_data.get_nodes_number();
	for (int i = 0; i < k; i++)
	{
		input >> buff;
		nodes[i].number = (int)extract_number(buff);
		input >> buff;
		nodes[i].x = extract_number(buff);
		input >> buff;
		nodes[i].y = extract_number(buff);
		std::getline(input, buff);
		nodes[i].BC = 0;
	}
	//czytanie elementow
	std::getline(input, buff);
	int l = glo_data.get_elements_number();
	for (int i = 0; i < l; i++)
	{
		input >> buff;
		elements[i].number = (int)extract_number(buff);
		for (int j = 0; j < 4; j++)
		{
			input >> buff;
			for (int m = 0; m < k; m++)
			{
				if (extract_number(buff) == nodes[m].number)
				{
					elements[i].nodes[j] = nodes[m];
				}
			}
		}
		std::getline(input, buff);
	}
	//czytanie BC
	std::getline(input, buff);
	while (!input.eof())
	{
		int BC;
		input >> BC;;
		for (int i = 0; i < glo_data.elements_number; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (elements[i].nodes[j].number == BC)
				{
					elements[i].nodes[j].BC = 1;
				}
			}
		}
	}
	//tworzenie gridu 
	grd.set_nodes_number(glo_data.nodes_number);
	grd.set_elements_number(glo_data.elements_number);
	grd.allocate_grid();
	grd.set_elements(elements, glo_data.elements_number);
	grd.set_nodes(nodes, glo_data.nodes_number);
	input.close();
}
Global_data File_loader::get_global_data()
{
	return glo_data;
}
Element* File_loader::get_elements()
{
	return elements;
}
Node* File_loader::get_nodes()
{
	return nodes;
}
Grid File_loader::get_grid()
{
	return grd;
}