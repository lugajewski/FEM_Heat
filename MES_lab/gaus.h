#pragma once
#include<math.h>
class gaus
{
	double* wezly;
	double* waga;
	double wynik;
	int ilosc;
public:
	gaus(int ilosc_wezlow);
	double licz(double fun(double));
	double licz(double fun(double,double));
	~gaus();
};