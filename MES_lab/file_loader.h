#pragma once
#include<string>
#include<sstream>
#include<iostream>
#include<fstream>

#include"node.h"
#include"element.h"
#include"grid.h"
#include"global_data.h"
class File_loader {
	Global_data glo_data;
	Element* elements;
	Node* nodes;
	Grid grd;
public:
	double extract_number(std::string string);
	void load_data_from_file(std::string file);
	Global_data get_global_data();
	Element* get_elements();
	Node* get_nodes();
	Grid get_grid();
};