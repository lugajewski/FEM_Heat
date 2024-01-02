#pragma once
#include"grid.h"

void Grid::allocate_grid()
{
	this->nodes = new Node[nodes_number];
	this->elements = new Element[elements_number];
}
void Grid::delloc_gird()
{
	delete[] nodes;
	delete[] elements;
}
void Grid::set_nodes_number(int nodes_number)
{
	this->nodes_number = nodes_number;
}
int Grid::get_nodes_number()
{
	return this->nodes_number;
}
void Grid::set_elements_number(int elements_number)
{
	this->elements_number = elements_number;
}
int Grid::get_elements_number()
{
	return this->elements_number;
}
void Grid::set_nodes(Node* nodes, int nodes_number)
{
	for (int i = 0; i < nodes_number; i++)
	{
		this->nodes[i] = nodes[i];
	}
}
Node* Grid::get_nodes()
{
	return this->nodes;
}
void Grid::set_elements(Element* elements, int elements_number)
{
	for (int i = 0; i < elements_number; i++)
	{
		this->elements[i] = elements[i];
	}
}
Element* Grid::get_elements()
{
	return this->elements;
}
void Grid::read()
{
	std::cout << "Elementy :" << std::endl;
	for (int i = 0; i < this->elements_number; i++)
	{
		this->elements[i].read();
	}
	std::cout << "Wezly :" << std::endl;
	for (int i = 0; i < this->nodes_number; i++)
	{
		this->nodes[i].read();
	}
}
void Grid::set_global_data(Global_data global_data)
{
	this->glb_data = global_data;
}
Global_data Grid::get_global_data()
{
	return this->glb_data;
}