#include "surface.h"

void Surface::set_size(int liczba_punktow_calkowania)
{
	N = new double* [liczba_punktow_calkowania];
	for (int i = 0; i < liczba_punktow_calkowania; i++)
	{
		N[i] = new double[4];
	}
	this->ilosc_wezlow = liczba_punktow_calkowania;
}
void Surface::read()
{
	for (int i = 0;i < this->ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << this->N[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
Surface::Surface()
{

}