#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"data_struct.h"

class input_loader : public global_data :public node :public element: public:grid
{
	global_data gd;
	node *nd;
	element *el;
	grid gr;
	public:
		input_loader(std::string file);
		void get_nodes(node* pointer, int number);
		void get_elements(element* pointer, int number);
		void get_grid(grid* pointer);
		void get_global_data(global_data* pointer); void get_all(node* p1, int number_of_nodes, element* p2, int number_of_elements, grid* p3, global_data* p4);
		void dest();
};
