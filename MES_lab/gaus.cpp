#include"gaus.h"

gaus::gaus(int ilosc_wezlow)
{
	ilosc = ilosc_wezlow;
	if (ilosc_wezlow == 1)
	{
		wezly = new double[1];
		wezly[0] = 0.0;
		waga = new double[1];
		waga[0] = 2.0;
	}
	else if (ilosc_wezlow == 2)
	{
		wezly = new double[2];
		wezly[0] = -1.0 * sqrt((1.0 / 3.0));
		wezly[1] = sqrt((1.0 / 3.0));
		waga = new double[2];
		waga[0] = 1;
		waga[1] = 1;
	}
	else if (ilosc_wezlow == 3)
	{
		wezly = new double[3];
		wezly[0] = -1.0 * sqrt((3.0 / 5.0));
		wezly[1] = 0.0;
		wezly[2] = sqrt((3.0 / 5.0));
		waga = new double[3];
		waga[0] = (5.0 / 9.0);
		waga[1] = (8.0 / 9.0);
		waga[2] = (5.0 / 9.0);
	}
	else if (ilosc_wezlow == 4)
	{
		wezly = new double[4];
		wezly[0] = -1 * sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[1] = -1 * sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[2] = sqrt((3.0 / 7.0) - (2.0 / 7.0) * sqrt(6.0 / 5.0));
		wezly[3] = sqrt((3.0 / 7.0) + (2.0 / 7.0) * sqrt(6 / 5));
		waga = new double[4];
		waga[0] = (18.0 + sqrt(30.0)) / 36.0;
		waga[1] = (18.0 - sqrt(30.0)) / 36.0;
		waga[2] = (18.0 + sqrt(30.0)) / 36.0;
		waga[3] = (18.0 - sqrt(30.0)) / 36.0;
	}
	else if (ilosc_wezlow == 5)
	{
		wezly = new double[5];
		wezly[0] = -1.0 * (1.0 / 3.0) * sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0));
		wezly[1] = -1.0 * (1.0 / 3.0) * sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0));
		wezly[2] = 0.0;
		wezly[3] = (1.0 / 3.0) * sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0));
		wezly[4] = (1.0 / 3.0) * sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0));
		waga = new double[5];
		waga[0] = ((322.0 + 13.0 * sqrt(70.0)) / 900.0);
		waga[1] = ((322.0 - 13.0 * sqrt(70.0)) / 900.0);
		waga[2] = (128.0 / 225.0);
		waga[3] = ((322.0 + 13.0 * sqrt(70.0)) / 900.0);
		waga[4] = ((322.0 - 13.0 * sqrt(70.0)) / 900.0);
	}
}

double gaus::licz(double fun(double x))
{
	wynik = 0;
	for (int i = 0; i < ilosc; i++)
	{
		wynik += waga[i] * fun(wezly[i]);
	}
	return wynik;
}

double gaus::licz(double fun(double x, double y))
{
	wynik = 0;
	for (int i = 0; i < ilosc; i++)
	{
		for (int j = 0; j < ilosc; j++)
		{
			wynik = wynik + waga[i] * waga[j] * fun(wezly[i], wezly[j]);
		}
	}
	return wynik;
}

gaus::~gaus()
{
	delete[] waga;
	delete[] wezly;
}
