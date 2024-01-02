#pragma once
#include"universal_element.h"

double Universal_element::N1(double Ksi, double Eta)
{
	return (1.0 / 4.0) * (1.0 - Ksi) * (1.0 - Eta);
}
double Universal_element::N2(double Ksi, double Eta)
{
	return (1.0 / 4.0) * (1.0 + Ksi) * (1.0 - Eta);
}
double Universal_element::N3(double Ksi, double Eta)
{
	return (1.0 / 4.0) * (1.0 + Ksi) * (1.0 + Eta);
}
double** Universal_element::get_NKsiEta()
{
	return this->NKsiEta;
}
double Universal_element::N4(double Ksi, double Eta)
{
	return (1.0 / 4.0) * (1.0 - Ksi) * (1.0 + Eta);
}
double Universal_element::N1poKsi(double Eta)
{
	return ((-1.0 / 4.0) * (1.0 - Eta));
}
double Universal_element::N2poKsi(double Eta)
{
	return ((1.0 / 4.0) * (1.0 - Eta));
}
double Universal_element::N3poKsi(double Eta)
{
	return ((1.0 / 4.0) * (1.0 + Eta));
}
double Universal_element::N4poKsi(double Eta)
{
	return ((-1.0 / 4.0) * (1.0 + Eta));
}
double Universal_element::N1poEta(double Ksi)
{
	return ((-1.0 / 4.0) * (1.0 - Ksi));
}
double Universal_element::N2poEta(double Ksi)
{
	return ((-1.0 / 4.0) * (1.0 + Ksi));
}
Surface* Universal_element::get_surface()
{
	return this->surface;
}
double Universal_element::N3poEta(double Ksi)
{
	return ((1.0 / 4.0) * (1.0 + Ksi));
}
double Universal_element::N4poEta(double Ksi)
{
	return ((1.0 / 4.0) * (1.0 - Ksi));
}
Universal_element::Universal_element(int ilosc_wezlow)
{
	//wypelnianie i alokacja dynamiczna
	this->ilosc_wezlow = ilosc_wezlow;
	NpoKsi = new double* [ilosc_wezlow * ilosc_wezlow];
	NpoEta = new double* [ilosc_wezlow * ilosc_wezlow];
	NKsiEta = new double* [ilosc_wezlow * ilosc_wezlow];
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		NpoKsi[i] = new double[4];
		NpoEta[i] = new double[4];
		NKsiEta[i] = new double[4];
	}
	//wypelnianie wezlow i wag
	if (ilosc_wezlow == 1)
	{
		wezly = new double[1];
		wezly[0] = 0.0;
		wagi = new double[1];
		wagi[0] = 2.0;
	}
	else if (ilosc_wezlow == 2)
	{
		wezly = new double[2];
		wezly[0] = -1.0 * sqrt((1.0 / 3.0));
		wezly[1] = sqrt((1.0 / 3.0));
		wagi = new double[2];
		wagi[0] = 1;
		wagi[1] = 1;
	}
	else if (ilosc_wezlow == 3)
	{
		wezly = new double[3];
		wezly[0] = -1.0 * sqrt((3.0 / 5.0));
		wezly[1] = 0.0;
		wezly[2] = sqrt((3.0 / 5.0));
		wagi = new double[3];
		wagi[0] = (5.0 / 9.0);
		wagi[1] = (8.0 / 9.0);
		wagi[2] = (5.0 / 9.0);
	}
	else if (ilosc_wezlow == 4)
	{
		wezly = new double[4];
		wezly[0] = -1 * sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[1] = -1 * sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[2] = sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[3] = sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6 / 5));
		wagi = new double[4];
		wagi[0] = (18.0 + sqrt(30.0)) / 36.0;
		wagi[1] = (18.0 - sqrt(30.0)) / 36.0;
		wagi[2] = (18.0 + sqrt(30.0)) / 36.0;
		wagi[3] = (18.0 - sqrt(30.0)) / 36.0;
	}
	else //(ilosc_wezl == 5)
	{
		wezly = new double[5];
		wezly[0] = -1.0 * (1.0 / 3.0) * sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0));
		wezly[1] = -1.0 * (1.0 / 3.0) * sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0));
		wezly[2] = 0.0;
		wezly[3] = (1.0 / 3.0) * sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0));
		wezly[4] = (1.0 / 3.0) * sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0));
		wagi = new double[5];
		wagi[0] = ((322.0 + 13.0 * sqrt(70.0)) / 900.0);
		wagi[1] = ((322.0 - 13.0 * sqrt(70.0)) / 900.0);
		wagi[2] = (128.0 / 225.0);
		wagi[3] = ((322.0 + 13.0 * sqrt(70.0)) / 900.0);
		wagi[4] = ((322.0 - 13.0 * sqrt(70.0)) / 900.0);
	}
	//punkty lokalne
	local_pointsKsi = new double[ilosc_wezlow * ilosc_wezlow];
	local_pointsEta = new double[ilosc_wezlow * ilosc_wezlow];
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		local_pointsKsi[i] = wezly[(i % ilosc_wezlow)];
		local_pointsEta[i] = wezly[(i / ilosc_wezlow)];
	}
	//surface
	surface = new Surface[4];
	for (int i = 0; i < 4; i++)
	{
		surface[i].set_size(ilosc_wezlow);
	}
	//obliczanie surface
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < ilosc_wezlow; j++)
		{
			if (i == 0)
			{
				surface[i].N[j][0] = N1(wezly[j], -1.0);
				surface[i].N[j][1] = N2(wezly[j], -1.0);
				surface[i].N[j][2] = N3(wezly[j], -1.0);
				surface[i].N[j][3] = N4(wezly[j], -1.0);
			}
			else if (i == 1)
			{
				surface[i].N[j][0] = N1(1.0, wezly[j]);
				surface[i].N[j][1] = N2(1.0,wezly[j]);
				surface[i].N[j][2] = N3(1.0, wezly[j]);
				surface[i].N[j][3] = N4(1.0, wezly[j]);
			}
			else if (i == 2)
			{
				surface[i].N[j][0] = N1(wezly[j], 1.0);
				surface[i].N[j][1] = N2(wezly[j], 1.0);
				surface[i].N[j][2] = N3(wezly[j], 1.0);
				surface[i].N[j][3] = N4(wezly[j], 1.0);
			}
			else
			{
				surface[i].N[j][0] = N1(-1.0, wezly[j]);
				surface[i].N[j][1] = N2(-1.0, wezly[j]);
				surface[i].N[j][2] = N3(-1.0, wezly[j]);
				surface[i].N[j][3] = N4(-1.0, wezly[j]);
			}
		}
	}


	//liczenie NpoKsi i NpoEta
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		NpoKsi[i][0] = N1poKsi(local_pointsEta[i]);
		NpoKsi[i][1] = N2poKsi(local_pointsEta[i]);
		NpoKsi[i][2] = N3poKsi(local_pointsEta[i]);
		NpoKsi[i][3] = N4poKsi(local_pointsEta[i]);
		NpoEta[i][0] = N1poEta(local_pointsKsi[i]);
		NpoEta[i][1] = N2poEta(local_pointsKsi[i]);
		NpoEta[i][2] = N3poEta(local_pointsKsi[i]);
		NpoEta[i][3] = N4poEta(local_pointsKsi[i]);
		NKsiEta[i][0] = N1(local_pointsKsi[i], local_pointsEta[i]);
		NKsiEta[i][1] = N2(local_pointsKsi[i], local_pointsEta[i]);
		NKsiEta[i][2] = N3(local_pointsKsi[i], local_pointsEta[i]);
		NKsiEta[i][3] = N4(local_pointsKsi[i], local_pointsEta[i]);
	}
}
void Universal_element::read()
{
	std::cout << "N po Ksi :" << std::endl;
	for (int i = 0; i < ilosc_wezlow*ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << NpoKsi[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "N po Eta" << std::endl;
	for (int i = 0; i < ilosc_wezlow*ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << NpoEta[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Surface:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		surface[i].read();
		std::cout << std::endl;
	}
}
double** Universal_element::get_NpoEta()
{
	return NpoEta;
}
double** Universal_element::get_NpoKsi()
{
	return NpoKsi;
}
double* Universal_element::get_local_pointsEta()
{
	return local_pointsEta;
}
double* Universal_element::get_local_pointsKsi()
{
	return local_pointsKsi;
}
double* Universal_element::get_wagi()
{
	return wagi;
}
double* Universal_element::get_wezly()
{
	return wezly;
}