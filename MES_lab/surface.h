#pragma once
#include<iostream>
class Surface
{
	double** N;
	int ilosc_wezlow;
	friend class Universal_element;
	friend class Element;
public:
	Surface();
	void set_size(int liczba_punktow_calkowania);
	void read();
};

