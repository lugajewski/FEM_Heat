#pragma once
#include<math.h>
#include<iostream>
#include"matrix.h"

class punkt {
	friend class universal_element;
	double x;
	double y;
public:
	punkt(double x, double y);
	punkt();
	void setxy(double x, double y);
	friend std::ostream& operator<<(std::ostream& os, const punkt& punkt);
};
class surface {
	friend class universal_element;
	double** N;
};

class universal_element {
	double** Dks;
	double** Det;
	double** Dx;
	surface* Surface[4];
	double** Dy;
	Matrix *H_posrednie;
	Matrix H;
	double* Dxe;
	double* Dye;
	double* Dxk;
	double* Dyk;
	double* Jakobiany;
	Matrix* Jakob;
	Matrix* Jakob_odwrotne;
	int ilosc_wezlow;
	punkt* local_points;
	punkt* global_points;
	punkt* surface_points;
	double* wezly;
	double* waga;
public:
	universal_element(int wezly, punkt *punkty_globalne, double conductivity);
	universal_element();
	void calculate(int wezly, punkt* punkty_globalne, double conductivity);
	void set_globalpoints(punkt *punkty_globalne);
	void read_dksdet();
	void read_dxedxk();
	void read_dyedyk();
	void read_dxdy();
	void read_jakobiany();
	void read_H_posrednie();
	void read_H();
	double Jakobian(int punkt_calkowania);
	double N1e(double n);
	double N2e(double n);
	double N3e(double n);
	double N4e(double n);
	double N1n(double e);
	double N2n(double e);
	double N3n(double e);
	double N4n(double e);
};

std::ostream& operator<<(std::ostream& os, const punkt& punkt);