#pragma once
#include<iostream>

#include "node.h"
#include "element.h"
#include "global_data.h"
class Grid {
	friend class File_loader;
	int nodes_number;
	int elements_number;
	Node* nodes;
	Element* elements;
	Global_data glb_data;
public:
	//Grid();
	//~Grid();
	void allocate_grid();
	void delloc_gird();
	void set_nodes_number(int nodes_number);
	int get_nodes_number();
	void set_elements_number(int elements_number);
	int get_elements_number();
	void set_nodes(Node* nodes, int nodes_number);
	Node* get_nodes();
	void set_elements(Element* elements, int elements_number);
	Element* get_elements();
	void set_global_data(Global_data global_data);
	Global_data get_global_data();
	void read();
};