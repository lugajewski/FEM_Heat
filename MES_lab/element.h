#pragma once
#include<iostream>
#include<math.h>
#include"node.h"
#include"matrix.h"
#include"surface.h"
class Element
{
	friend class File_loader;
	friend class Grid;
public:
	Node* nodes;
	int number;
	Matrix P;
	Matrix* P_glob;

	Matrix* H_glob;
	Matrix* C_glob;
	Matrix Hbc;
	int nodes_number;
	double initial_temp;
	double ro;
	double cp;
	double* waga;
	double* wezly;
	double alfa;
	double* XpoEta;
	double* XpoKsi;
	double* YpoEta;
	double* YpoKsi;
	double* Jakobiany;
	Matrix* Macierze_Jakobiego;
	Matrix* Macierze_Jakobiego_odwrotne;
	double** NpoX;
	double** NpoY;
	double** NKsiEta;
	double k;
	Matrix* Hbc_posrednie;
	Matrix* C_posrednie;
	Matrix H;
	Matrix C_pro;
	Matrix* H_posrednie;
	Surface* surface;
public:
	void set_initial_temp(double initial_temp);
	void allocate_element();
	void set_P_glob(Matrix* P_glob);
	void set_ro(double ro);
	void set_cp(double cp);
	Element();
	~Element();
	void set_H_glob(Matrix* H_glob);
	void set_C_glob(Matrix* C_glob);
	void set_nodes(Node* nodes);
	Matrix calc_P_posrednie(Node* nodes, int i);
	Node* get_nodes();
	void set_alfa(double alfa);
	double get_alfa();
	void set_nodes_number(int number);
	void set_k(double k);
	int get_nodes_number();
	void calculate();
	void read_calculations();
	void set_number(int number);
	int get_number();
	void read();
	Matrix calc_Hbc_posrednie(Node* nodes, int i);
	void operator=(const Element & element);
};