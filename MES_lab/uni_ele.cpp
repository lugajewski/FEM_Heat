#include "uni_ele.h"

double universal_element::N1e(double n)
{
	return ((-1.0 / 4.0) * (1.0 - n));
}
double universal_element::N2e(double n)
{
	return ((1.0 / 4.0) * (1.0 - n));
}
double universal_element::N3e(double n)
{
	return ((1.0 / 4.0) * (1.0 + n));
}
double universal_element::N4e(double n)
{
	return ((-1.0 / 4.0) * (1.0 + n));
}
punkt::punkt(double x, double y)
{
	this->x = x;
	this->y = y;
}
punkt::punkt()
{
	this->x = 0;
	this->y = 0;
}
std::ostream& operator<<(std::ostream& os, const punkt& punkt)
{
	os << "x = " << punkt.x << " y = " << punkt.y << std::endl;
	return os;
}


double universal_element::N1n(double e)
{
	return ((-1.0 / 4.0) * (1.0 - e));
}
double universal_element::N2n(double e)
{
	return ((-1.0 / 4.0) * (1.0 + e));
}
double universal_element::N3n(double e)
{
	return ((1.0 / 4.0) * (1.0 + e));
}
double universal_element::N4n(double e)
{
	return ((1.0 / 4.0) * (1.0 - e));
}
void universal_element::set_globalpoints(punkt* punkty_globalne)
{
	for (int i = 0;i < 4; i++)
	{
		global_points[i] = punkty_globalne[i];
	}
}
void universal_element::read_dksdet()
{
	std::cout << "Dks:" << std::endl;
	for (int i = 0; i < this->ilosc_wezlow * this->ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << Dks[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Det:" << std::endl;
	for (int i = 0; i < this->ilosc_wezlow * this->ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << Det[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void punkt::setxy(double x, double y)
{
	this->x = x;
	this->y = y;
}
void universal_element::read_dxedxk()
{
	std::cout << "Dxe:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << Dxe[i] << std::endl;
	}
	std::cout << "Dxk:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << Dxk[i] << std::endl;
	}
}
void universal_element::read_dyedyk()
{
	std::cout << "Dye:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << Dye[i] << std::endl;
	}
	std::cout << "Dyk:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << Dyk[i] << std::endl;
	}
}
void universal_element::read_jakobiany()
{
	std::cout << "Jakobiany:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << Jakobiany[i] << std::endl;
	}
	std::cout << "Macierze Jakobiego:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Jakob[i].read();
	}
	std::cout << "Macierze Jakobiego odwrotne:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Jakob_odwrotne[i].read();
	}
}
void universal_element::read_dxdy()
{
	std::cout << "Dx:" << std::endl;
	for (int i = 0; i < this->ilosc_wezlow * this->ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << Dx[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Dy:" << std::endl;
	for (int i = 0; i < this->ilosc_wezlow * this->ilosc_wezlow; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << Dy[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void universal_element::read_H_posrednie()
{
	std::cout << "H_posrednie:" << std::endl;
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		std::cout << "Punkt " << i << " " << std::endl;
		H_posrednie[i].read();
	}
}
void universal_element::read_H()
{
	std::cout << "H:" << std::endl;
	H.read();
}

universal_element::universal_element(int ilosc_wezl, punkt * punkty_globalne, double conductivity)
{
	this->ilosc_wezlow = ilosc_wezl;
	//alokacja dynamiczna tablicy 
	//for (int i = 0; i < 4; i++)
	//{
	//	Surface[i]->N = new double* [ilosc_wezlow];
	//	for (int j = 0; j < ilosc_wezlow; j++)
	//	{
	//		Surface[i]->N[j] = new double[4];
	//	}
	//}
	Jakob = new Matrix[ilosc_wezlow * ilosc_wezl];
	Jakob_odwrotne = new Matrix[ilosc_wezlow * ilosc_wezl];
	surface_points = new punkt[ilosc_wezlow * ilosc_wezlow+4];
	local_points = new punkt[ilosc_wezl*ilosc_wezl];
	global_points = new punkt[ilosc_wezl * ilosc_wezl];
	H_posrednie = new Matrix[ilosc_wezlow*ilosc_wezlow];
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		global_points[i] = punkty_globalne[i];
		Jakob[i].resize(2, 2);
		Jakob_odwrotne[i].resize(2, 2);
		H_posrednie[i].resize(4, 4);
	}
	Dks = new double* [ilosc_wezl*ilosc_wezl];
	Det = new double* [ilosc_wezl*ilosc_wezl];
	Dx = new double* [ilosc_wezl * ilosc_wezl];
	Dy = new double* [ilosc_wezl * ilosc_wezl];
	Dxe = new double [ilosc_wezl * ilosc_wezl];
	Dye = new double [ilosc_wezl * ilosc_wezl];
	Dxk = new double[ilosc_wezl * ilosc_wezl];
	Dyk = new double[ilosc_wezl * ilosc_wezl];
	Jakobiany = new double[ilosc_wezl * ilosc_wezl];
	for (int i = 0; i < ilosc_wezl*ilosc_wezl; i++)
	{
		Dks[i] = new double[4];
		Det[i] = new double[4];
		Dx[i] = new double[4];
		Dy[i] = new double[4];
	}
	//wypelnianie wezlow z gausa
	if (ilosc_wezl == 1)
	{
		wezly = new double[1];
		wezly[0] = 0.0;
		waga = new double[1];
		waga[0] = 2.0;
	}
	else if (ilosc_wezl == 2)
	{
		wezly = new double[2];
		wezly[0] = -1.0 * sqrt((1.0 / 3.0));
		wezly[1] = sqrt((1.0 / 3.0));
		waga = new double[2];
		waga[0] = 1;
		waga[1] = 1;
	}
	else if (ilosc_wezl == 3)
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
	else if (ilosc_wezl == 4)
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
	else //(ilosc_wezl == 5)
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
	//wypelnianie punktow na powierzchni
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow+4; i++)
	{
		if (i < (ilosc_wezlow*ilosc_wezlow+4)/4)
		{
			surface_points[i].setxy(wezly[i % ilosc_wezlow], -1.0);
		}
		else if (i >= (ilosc_wezlow*ilosc_wezlow+4)/4 && i < ((ilosc_wezlow * ilosc_wezlow+ 4)/2))
		{
			surface_points[i].setxy(1.0, wezly[i % ilosc_wezlow]);
		}
		else if (i >= ((ilosc_wezlow *ilosc_wezlow+ 4)/2) && i < (((ilosc_wezlow* ilosc_wezlow +4)/4)*3))
		{
			surface_points[i].setxy(wezly[i % ilosc_wezlow], 1.0);
		}
		else
		{
			surface_points[i].setxy(-1.0, wezly[i % ilosc_wezlow]);
		}
		std::cout << surface_points[i];
	}
	//wypelnianie punktow lokalnych wartosciami z wezlow
	for (int i = 0; i < ilosc_wezl*ilosc_wezl; i++)
	{
		local_points[i].x = wezly[(i % ilosc_wezl)];
		local_points[i].y = wezly[(i / ilosc_wezl)];
	}
	//liczenie pochodnych w punktach
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Dks[i][0] = N1e(local_points[i].y);
		Dks[i][1] = N2e(local_points[i].y);
		Dks[i][2] = N3e(local_points[i].y);
		Dks[i][3] = N4e(local_points[i].y);
		Det[i][0] = N1n(local_points[i].x);
		Det[i][1] = N2n(local_points[i].x);
		Det[i][2] = N3n(local_points[i].x);
		Det[i][3] = N4n(local_points[i].x);
	}
	//sumowanie do Dx
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Dxe[i] = Det[i][0] * global_points[0].x + Det[i][1] * global_points[1].x + Det[i][2] * global_points[2].x + Det[i][3] * global_points[3].x;
		Dxk[i] = Dks[i][0] * global_points[0].x + Dks[i][1] * global_points[1].x + Dks[i][2] * global_points[2].x + Dks[i][3] * global_points[3].x;
		Dye[i] = Det[i][0] * global_points[0].y + Det[i][1] * global_points[1].y + Det[i][2] * global_points[2].y + Det[i][3] * global_points[3].y;
		Dyk[i] = Dks[i][0] * global_points[0].y + Dks[i][1] * global_points[1].y + Dks[i][2] * global_points[2].y + Dks[i][3] * global_points[3].y;
	}
	//liczenie jakobianow
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Jakob[i].set_values(0, 0, Dxk[i]);
		Jakob[i].set_values(0, 1, Dyk[i]);
		Jakob[i].set_values(1, 0, Dxe[i]);
		Jakob[i].set_values(1, 1, Dye[i]);
		Jakobiany[i] = Jakob[i].deter();
		Matrix temp;
		temp = Jakob[i];
		Jakob_odwrotne[i] = temp.reverse();
	}
	//Obliczanie Dxow 
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Matrix A(1, 2);
		Matrix B(1, 2);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, 0, Dks[i][j]);
			A.set_values(0, 1, Det[i][j]);
			B = A * Jakob_odwrotne[i];
			Dx[i][j] = B.get_value(0, 0);
			Dy[i][j] = B.get_value(0, 1);
		}
	}
	//Obliczanie H_posrednich
	for (int i = 0; i < ilosc_wezlow*ilosc_wezlow; i++)
	{
		Matrix A(1, 4);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, j, Dx[i][j]);
		}
		Matrix B(4, 1);
		B = A.transpose();
		Matrix C(4, 4);
		C = B * A;
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, j, Dy[i][j]);
		}
		B = A.transpose();
		Matrix D(4, 4);
		D = B * A;
		Matrix E(4, 4);
		E = C + D;
		double k = conductivity;
		E = E * k;
		E = E * Jakobiany[i];
		H_posrednie[i] = E;
	}
	//obliczanie H
	H.resize(4, 4);
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Matrix A(4, 4);
		double B = waga[i % ilosc_wezlow] * waga[i / ilosc_wezlow];
		A = H_posrednie[i] * B;
		H = H + A;
	}
}
universal_element::universal_element()
{

}
void universal_element::calculate(int ilosc_wezl, punkt* punkty_globalne, double conductivity)
{
	this->ilosc_wezlow = ilosc_wezl;
	//alokacja dynamiczna tablicy 
	for (int i = 0; i < 4; i++)
	{
		Surface[i]->N = new double* [ilosc_wezlow];
		for (int j = 0; j < ilosc_wezlow; j++)
		{
			Surface[i]->N[j] = new double[4];
		}
	}
	Jakob = new Matrix[ilosc_wezlow * ilosc_wezl];
	Jakob_odwrotne = new Matrix[ilosc_wezlow * ilosc_wezl];
	local_points = new punkt[ilosc_wezl * ilosc_wezl];
	global_points = new punkt[ilosc_wezl * ilosc_wezl];
	surface_points = new punkt[ilosc_wezlow * ilosc_wezlow];
	H_posrednie = new Matrix[ilosc_wezlow * ilosc_wezlow];
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		global_points[i] = punkty_globalne[i];
		Jakob[i].resize(2, 2);
		Jakob_odwrotne[i].resize(2, 2);
		H_posrednie[i].resize(4, 4);
	}
	Dks = new double* [ilosc_wezl * ilosc_wezl];
	Det = new double* [ilosc_wezl * ilosc_wezl];
	Dx = new double* [ilosc_wezl * ilosc_wezl];
	Dy = new double* [ilosc_wezl * ilosc_wezl];
	Dxe = new double[ilosc_wezl * ilosc_wezl];
	Dye = new double[ilosc_wezl * ilosc_wezl];
	Dxk = new double[ilosc_wezl * ilosc_wezl];
	Dyk = new double[ilosc_wezl * ilosc_wezl];
	Jakobiany = new double[ilosc_wezl * ilosc_wezl];
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Dks[i] = new double[4];
		Det[i] = new double[4];
		Dx[i] = new double[4];
		Dy[i] = new double[4];
	}
	//wypelnianie wezlow z gausa
	if (ilosc_wezl == 1)
	{
		wezly = new double[1];
		wezly[0] = 0.0;
		waga = new double[1];
		waga[0] = 2.0;
	}
	else if (ilosc_wezl == 2)
	{
		wezly = new double[2];
		wezly[0] = -1.0 * sqrt((1.0 / 3.0));
		wezly[1] = sqrt((1.0 / 3.0));
		waga = new double[2];
		waga[0] = 1;
		waga[1] = 1;
	}
	else if (ilosc_wezl == 3)
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
	else if (ilosc_wezl == 4)
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
	else //(ilosc_wezl == 5)
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
	//wypelnianie punktow na powierzchni
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		if (i < ilosc_wezlow)
		{
			surface_points[i].setxy(wezly[i % ilosc_wezlow], -1);
		}
		else if (i >= ilosc_wezlow && i < (ilosc_wezlow * 2))
		{
			surface_points[i].setxy(1, wezly[i % ilosc_wezlow]);
		}
		else if (i >= (ilosc_wezlow * 2) && i < (ilosc_wezlow * 3))
		{
			surface_points[i].setxy(wezly[i % ilosc_wezlow], 1);
		}
		else
		{
			surface_points[i].setxy(-1, wezly[i % ilosc_wezlow]);
		}
		std::cout << surface_points[i];
	}
	//wypelnianie punktow lokalnych wartosciami z wezlow
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		local_points[i].x = wezly[(i % ilosc_wezl)];
		local_points[i].y = wezly[(i / ilosc_wezl)];
	}
	//liczenie pochodnych w punktach
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Dks[i][0] = N1e(local_points[i].y);
		Dks[i][1] = N2e(local_points[i].y);
		Dks[i][2] = N3e(local_points[i].y);
		Dks[i][3] = N4e(local_points[i].y);
		Det[i][0] = N1n(local_points[i].x);
		Det[i][1] = N2n(local_points[i].x);
		Det[i][2] = N3n(local_points[i].x);
		Det[i][3] = N4n(local_points[i].x);
	}
	//sumowanie do Dx
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Dxe[i] = Det[i][0] * global_points[0].x + Det[i][1] * global_points[1].x + Det[i][2] * global_points[2].x + Det[i][3] * global_points[3].x;
		Dxk[i] = Dks[i][0] * global_points[0].x + Dks[i][1] * global_points[1].x + Dks[i][2] * global_points[2].x + Dks[i][3] * global_points[3].x;
		Dye[i] = Det[i][0] * global_points[0].y + Det[i][1] * global_points[1].y + Det[i][2] * global_points[2].y + Det[i][3] * global_points[3].y;
		Dyk[i] = Dks[i][0] * global_points[0].y + Dks[i][1] * global_points[1].y + Dks[i][2] * global_points[2].y + Dks[i][3] * global_points[3].y;
	}
	//liczenie jakobianow
	for (int i = 0; i < ilosc_wezl * ilosc_wezl; i++)
	{
		Jakob[i].set_values(0, 0, Dxk[i]);
		Jakob[i].set_values(0, 1, Dyk[i]);
		Jakob[i].set_values(1, 0, Dxe[i]);
		Jakob[i].set_values(1, 1, Dye[i]);
		Jakobiany[i] = Jakob[i].deter();
		Matrix temp;
		temp=Jakob[i];
		Jakob_odwrotne[i] = temp.reverse();
	}
	//Obliczanie Dxow 
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Matrix A(1, 2);
		Matrix B(1, 2);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, 0, Dks[i][j]);
			A.set_values(0, 1, Det[i][j]);
			B = A * Jakob_odwrotne[i];
			Dx[i][j] = B.get_value(0, 0);
			Dy[i][j] = B.get_value(0, 1);
		}
	}
	//Obliczanie H_posrednich
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Matrix A(1, 4);
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, j, Dx[i][j]);
		}
		Matrix B(4, 1);
		B = A.transpose();
		Matrix C(4, 4);
		C = B * A;
		for (int j = 0; j < 4; j++)
		{
			A.set_values(0, j, Dy[i][j]);
		}
		B = A.transpose();
		Matrix D(4, 4);
		D = B * A;
		Matrix E(4, 4);
		E = C + D;
		double k = conductivity;
		E = E * k;
		E = E * Jakobiany[i];
		H_posrednie[i] = E;
	}
	//obliczanie H
	H.resize(4, 4);
	for (int i = 0; i < ilosc_wezlow * ilosc_wezlow; i++)
	{
		Matrix A(4, 4);
		double B = waga[i % ilosc_wezlow] * waga[i / ilosc_wezlow];
		A = H_posrednie[i] * B;
		H = H + A;
	}
}