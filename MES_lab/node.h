#pragma once
#include<iostream>
class Node {
	friend class Element;
	friend class Grid;
	friend class File_loader;
public:
	int number;
	double x;
	double y;
	int BC;
public:
	void set_BC(int BC);
	int get_BC();
	void set_number(int number);
	int get_number();
	void set_x(double x);
	double get_x();
	void set_y(double y);
	double get_y();
	void read();
	void operator=(const Node& node);
};