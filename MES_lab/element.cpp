#pragma once
#include"element.h"
#include"universal_element.h"
void Element::allocate_element()
{
	this->nodes = new Node[4];
}
Element::Element()
{
	this->allocate_element();
}
void Element::set_nodes_number(int number)
{
	this->nodes_number = number;
}
int Element::get_nodes_number()
{
	return this->nodes_number;
}
Element::~Element()
{
	delete[] nodes;
}
void Element::set_alfa(double alfa)
{
	this->alfa = alfa;
}
double Element::get_alfa()
{
	return this->alfa;
}
void Element::set_nodes(Node* nodes)
{
	for (int i = 0; i < 4; i++)
	{
		this->nodes[i] = nodes[i];
	}
}
Node* Element::get_nodes()
{
	return this->nodes;
}
void Element::set_number(int number)
{
	this->number = number;
}
int Element::get_number()
{
	return this->number;
}
void Element::set_ro(double ro)
{
	this->ro = ro;
}
void Element::set_cp(double cp)
{
	this->cp = cp;
}
void Element::set_C_glob(Matrix* C_glob)
{
	this->C_glob = C_glob;
}
void Element::set_H_glob(Matrix* H_glob)
{
	this->H_glob = H_glob;
}
void Element::read()
{
	std::cout << "Element nr:" << number << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->nodes[i].read();
	}
}
void Element::operator=(const Element& element)
{
	this->number = element.number;
	this->nodes = element.nodes;
}
void Element::set_k(double k)
{
	this->k = k;
}
void Element::set_P_glob(Matrix* P_glob)
{
	this->P_glob = P_glob;
}
void Element::set_initial_temp(double initial_temp)
{
	this->initial_temp = initial_temp;
}
Matrix Element::calc_Hbc_posrednie(Node* nodes, int i)
{
	Matrix wynik(4, 4);
	Universal_element u1(nodes_number);
	if (nodes[0].get_BC() == 0 || nodes[1].get_BC() == 0)
	{
		return wynik;
	}
	for (int j = 0; j < nodes_number; j++)
	{
		Matrix A(4, 1);
		for (int k = 0; k < 4; k++)
		{
			A.set_values(k, 0, u1.surface[i].N[j][k]);
		}
		Matrix B = A.transpose();
		wynik = wynik + A * B * this->waga[j];
	}
	wynik = wynik * alfa;
	double detJ = sqrt(pow(nodes[0].x - nodes[1].x, 2) + pow(nodes[0].y - nodes[1].y, 2)) / 2;
	wynik = wynik * detJ;
	return wynik;
}
Matrix Element::calc_P_posrednie(Node* nodes, int i)
{
	Matrix wynik(4, 1);
	Universal_element u1(nodes_number);
	if (nodes[0].get_BC() == 0 || nodes[1].get_BC() == 0)
	{
		return wynik;
	}
	for (int j = 0; j < nodes_number; j++)
	{
		Matrix A(4, 1);
		for (int k = 0; k < 4; k++)
		{
			A.set_values(k, 0, u1.surface[i].N[j][k]);
		}
		Matrix B = A * initial_temp;
		wynik = wynik + B * this->waga[j];
	}
	wynik = wynik * alfa;
	double detJ = sqrt(pow(nodes[0].x - nodes[1].x, 2) + pow(nodes[0].y - nodes[1].y, 2)) / 2;
	wynik = wynik * detJ;
	return wynik;
}
void Element::calculate()
{
	XpoEta = new double[nodes_number * nodes_number];
	XpoKsi = new double[nodes_number * nodes_number];
	YpoEta = new double[nodes_number * nodes_number];
	YpoKsi = new double[nodes_number * nodes_number];
	NpoX = new double*[nodes_number*nodes_number];
	NpoY = new double*[nodes_number*nodes_number];
	Jakobiany = new double[nodes_number * nodes_number];
	Macierze_Jakobiego = new Matrix[nodes_number * nodes_number];
	Macierze_Jakobiego_odwrotne = new Matrix[nodes_number * nodes_number];
	Universal_element universal(nodes_number);
	//pobieranie npoksieta z uni
	double** NpoKsi;
	double** NpoEta;
	NpoKsi = new double* [nodes_number * nodes_number];
	NpoEta = new double* [nodes_number * nodes_number];
	NKsiEta = new double* [nodes_number * nodes_number];
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		NpoKsi[i] = new double[4];
		NpoEta[i] = new double[4];
		NpoX[i] = new double[4];
		NpoY[i] = new double[4];
		NKsiEta[i] = new double[4];
	}
	NpoKsi = universal.get_NpoKsi();
	NpoEta = universal.get_NpoEta();
	NKsiEta = universal.get_NKsiEta();
	//liczenie xy po ksieta
	for (int i = 0; i < nodes_number * nodes_number;i++)
	{
		XpoEta[i] = 0.0;
		XpoKsi[i] = 0.0;
		YpoEta[i] = 0.0;
		YpoKsi[i] = 0.0;
		for (int j = 0; j < 4; j++)
		{
			XpoEta[i] += NpoEta[i][j] * nodes[j].x;
			XpoKsi[i] += NpoKsi[i][j] * nodes[j].x;
			YpoEta[i] += NpoEta[i][j] * nodes[j].y;
			YpoKsi[i] += NpoKsi[i][j] * nodes[j].y;
		}
	}
	//liczenie macierzy jakobiego odwr i jakobianow
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		Macierze_Jakobiego[i].resize(2, 2);
		Macierze_Jakobiego[i].set_values(0, 0, XpoKsi[i]);
		Macierze_Jakobiego[i].set_values(0, 1, YpoKsi[i]);
		Macierze_Jakobiego[i].set_values(1, 0, XpoEta[i]);
		Macierze_Jakobiego[i].set_values(1, 1, YpoEta[i]);
		Jakobiany[i] = Macierze_Jakobiego[i].deter();
		Macierze_Jakobiego_odwrotne[i] = Macierze_Jakobiego[i].reverse();
	}
	//liczenie NpoXY
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		Matrix A(2, 1);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, 0, NpoKsi[i][j]);
			A.set_values(1, 0, NpoEta[i][j]);
			Matrix B = (Macierze_Jakobiego_odwrotne[i] * A);
			NpoX[i][j] = B.get_value(0, 0);
			NpoY[i][j] = B.get_value(1, 0);
		}
	}
	//Obliczanie H_posrednich
	H_posrednie = new Matrix[nodes_number*nodes_number];
	C_posrednie = new Matrix[nodes_number * nodes_number];
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		Matrix A(4, 1);
		Matrix AA(4, 1);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(j, 0, NpoX[i][j]);
			AA.set_values(j, 0, NKsiEta[i][j]);
		}
		Matrix B = A.transpose();
		Matrix C = A * B;
		Matrix BB = AA.transpose();
		Matrix CC = AA * BB;
		for (int j = 0; j < 4; j++)
		{
			A.set_values(j, 0, NpoY[i][j]);
		}
		Matrix D = A.transpose();
		C = C + (A * D);
		C = C * k;
		C = C * Jakobiany[i];
		H_posrednie[i] = C;
		CC = CC * (this->ro * this->cp);
		CC = CC * Jakobiany[i];
		C_posrednie[i] = CC;
	}
	//obliczanie H
	H.resize(4, 4);
	C_pro.resize(4, 4);
	waga = new double[nodes_number];
	waga = universal.get_wagi();
	wezly = new double[nodes_number];
	wezly = universal.get_wezly();
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		double B = waga[i % nodes_number] * waga[i / nodes_number];
		Matrix A = H_posrednie[i] * B;
		H = H + A;
		A = C_posrednie[i] * B;
		C_pro = C_pro + A;
	}
	//obliczanie Hbc
	Hbc.resize(4, 4);
	Node* temp_nodes = new Node[2];
	temp_nodes[0] = this->nodes[0];
	temp_nodes[1] = this->nodes[1];
	Hbc = Hbc + calc_Hbc_posrednie(temp_nodes, 0);
	temp_nodes[0] = this->nodes[1];
	temp_nodes[1] = this->nodes[2];
	Hbc = Hbc + calc_Hbc_posrednie(temp_nodes, 1);
	temp_nodes[0] = this->nodes[2];
	temp_nodes[1] = this->nodes[3];
	Hbc = Hbc + calc_Hbc_posrednie(temp_nodes, 2);
	temp_nodes[0] = this->nodes[3];
	temp_nodes[1] = this->nodes[0];
	Hbc = Hbc + calc_Hbc_posrednie(temp_nodes, 3);
	//obliczanie P
	P.resize(4, 1);
	temp_nodes[0] = this->nodes[0];
	temp_nodes[1] = this->nodes[1];
	P = P + calc_P_posrednie(temp_nodes, 0);
	temp_nodes[0] = this->nodes[1];
	temp_nodes[1] = this->nodes[2];
	P = P + calc_P_posrednie(temp_nodes, 1);
	temp_nodes[0] = this->nodes[2];
	temp_nodes[1] = this->nodes[3];
	P = P + calc_P_posrednie(temp_nodes, 2);
	temp_nodes[0] = this->nodes[3];
	temp_nodes[1] = this->nodes[0];
	P = P + calc_P_posrednie(temp_nodes, 3);
	//olbliczanie H_globalnego i P_globalnego
	int ID[4];
	ID[0] = nodes[0].number;
	ID[1] = nodes[1].number;
	ID[2] = nodes[2].number;
	ID[3] = nodes[3].number;
	Matrix A = H + Hbc;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			H_glob->add_values(ID[i]-1, ID[j]-1, A.get_value(i,j));
			C_glob->add_values(ID[i]-1, ID[j]-1, C_pro.get_value(i,j));
		}
	}
	for (int i = 0; i < 4; i++)
	{
		P_glob->add_values(ID[i] - 1, 0, P.get_value(i, 0));
	}
}
void Element::read_calculations()
{
	std::cout <<std::endl<< "X po Eta" << std::endl;
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		std::cout << XpoEta[i] << std::endl;
	}
	std::cout <<std::endl<< "X po Ksi" << std::endl;
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		std::cout << XpoKsi[i] << std::endl;
	}
	std::cout << std::endl<< "Y po Eta" << std::endl;
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		std::cout << YpoEta[i] << std::endl;
	}
	std::cout << std::endl<< "Y po Ksi" << std::endl;
	for (int i = 0; i < nodes_number*nodes_number; i++)
	{
		std::cout << YpoKsi[i] << std::endl;
	}
	std::cout << std::endl << "N po X:" << std::endl;
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << NpoX[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "N po Y:" << std::endl;
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << NpoY[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "H_posrednie:" << std::endl;
	for (int i = 0; i < nodes_number * nodes_number; i++)
	{
		H_posrednie[i].read();
		std::cout << std::endl;
	}
	std::cout << std::endl << "H:" << std::endl;
	H.read();
	std::cout << std::endl << "Hbc:" << std::endl;
	Hbc.read();
	std::cout << std::endl << "P:" << std::endl;
	P.read();
	std::cout << std::endl << "C:" << std::endl;
	C_pro.read();
}