#pragma once
#include<math.h>
#include<iostream>

#include"matrix.h"
#include"surface.h"
class Universal_element {
	friend class Element;
	double** NpoKsi;
	double** NpoEta;
	double** NKsiEta;
	double* wezly;
	double* wagi;
	double* local_pointsKsi;
	double* local_pointsEta;
	int ilosc_wezlow;
	Surface* surface;
public:
	Universal_element(int ilosc_wezlow);
	void read();
	double** get_NKsiEta();
	double** get_NpoKsi();
	double** get_NpoEta();
	double* get_local_pointsKsi();
	double* get_local_pointsEta();
	double* get_wagi();
	double* get_wezly();
	Surface* get_surface();
	double N1(double Eta, double Ksi);
	double N2(double Eta, double Ksi);
	double N3(double Eta, double Ksi);
	double N4(double Eta, double Ksi);
	double N1poKsi(double Eta);
	double N2poKsi(double Eta);
	double N3poKsi(double Eta);
	double N4poKsi(double Eta);
	double N1poEta(double Ksi);
	double N2poEta(double Ksi);
	double N3poEta(double Ksi);
	double N4poEta(double Ksi);
};