#pragma once
#include"matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	values = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		values[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = 0.0;
		}
	}
}
Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	values = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		values[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = 0.0;
		}
	}
}
/*Matrix::~Matrix()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] values[i];
	}
	delete[] values;
}*/
void Matrix::read()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << values[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void Matrix::add_values(int row, int col, double value)
{
	if (this->rows <= row)
	{
		std::cout << "Blad macierzy" << std::endl;
	}
	else if (this->cols <= col)
	{
		std::cout << "Blad macierzy" << std::endl;
	}
	else
	{
		this->values[row][col] = this->values[row][col] + value;
	}
}
void Matrix::resize(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	values = new double* [this->rows];
	for (int i = 0; i < rows; i++)
	{
		values[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			values[i][j] = 0.0;
		}
	}
}
void Matrix::set_values(int row, int col, int value)
{
	if (this->rows < row)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	if (this->cols < col)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	this->values[row][col] = (double)value;
}
void Matrix::set_values(int row, int col, float value)
{
	if (this->rows < row)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	if (this->cols < col)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	this->values[row][col] = (double)value;
}
void Matrix::set_values(int row, int col, double value)
{
	if (this->rows < row)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	if (this->cols < col)
	{
		std::cout << "Blad wstawiania" << std::endl;
		return;
	}
	this->values[row][col] = value;
}
Matrix Matrix::operator+(const int& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] + (double)number;
		}
	}
	return wynik;
}
Matrix Matrix::operator+(const float& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] + (double)number;
		}
	}
	return wynik;
}
Matrix Matrix::operator+(const double& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] + number;
		}
	}
	return wynik;
}
Matrix Matrix::operator+(const Matrix& matrix)
{
	int la_rows, la_cols;
	if (this->rows < matrix.rows)
	{
		la_rows = this->rows;
	}
	else
	{
		la_rows = matrix.rows;
	}
	if (this->cols < matrix.cols)
	{
		la_cols = this->cols;
	}
	else
	{
		la_cols = matrix.cols;
	}
	Matrix wynik(la_rows, la_cols);
	for (int i = 0; i < la_rows; i++)
	{
		for (int j = 0; j < la_cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] + matrix.values[i][j];
		}
	}
	return wynik;
}
void Matrix::operator=(const int& number)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->values[i][j] = (double)number;
		}
	}
}
void Matrix::operator=(const float& number)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->values[i][j] = (double)number;
		}
	}
}
void Matrix::operator=(const double& number)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->values[i][j] = number;
		}
	}
}
void Matrix::operator=(const Matrix& matrix)
{
	this->rows = matrix.rows;
	this->cols = matrix.cols;
	this->resize(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->values[i][j] = matrix.values[i][j];
		}
	}
}
Matrix Matrix::operator*(const int& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] * (double)number;
		}
	}
	return wynik;
}
Matrix Matrix::operator*(const float& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] * (double)number;
		}
	}
	return wynik;
}
Matrix Matrix::operator*(const double& number)
{
	Matrix wynik(this->rows, this->cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			wynik.values[i][j] = this->values[i][j] * number;
		}
	}
	return wynik;
}
Matrix Matrix::operator*(const Matrix& matrix)
{
	Matrix wynik(this->rows, matrix.cols);
	if (this->cols != matrix.rows)
	{
		std::cout << "Nie mozna pomnozyc macierzy" << std::endl;
		return wynik;
	}
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < matrix.cols; j++)
		{
			double temp = 0.0;
			for (int k = 0; k < matrix.rows; k++)
			{
				temp = temp + this->values[i][k] * matrix.values[k][j];
			}
			wynik.values[i][j] = temp;
		}
	}
	return wynik;
}
double Matrix::get_value(int row, int col)
{
	return this->values[row][col];
}
double Matrix::deter(int n, int w, int* WK, double** A)
{
	int mnoznik;
	double rozwiniecie;
	if (n == 1)
	{
		return A[w][WK[0]];
	}
	else
	{
		int* kol = new int[n - 1];        // tworzymy dynamiczny wektor kolumn
		rozwiniecie = 0;                         // zerujemy wartoœæ rozwiniêcia
		mnoznik = 1;                         // pocz¹tkowy mno¿nik
		for (int i = 0; i < n; i++)       // pêtla obliczaj¹ca rozwiniêcie
		{
			int k = 0;                       // tworzymy wektor kolumn dla rekurencji
			for (int j = 0; j < n - 1; j++) // ma on o 1 kolumnê mniej ni¿ WK
			{
				if (k == i) k++;          // pomijamy bie¿¹c¹ kolumnê
				kol[j] = WK[k++];     // pozosta³e kolumny przenosimy do KK
			}
			rozwiniecie += mnoznik * A[w][WK[i]] * deter(n - 1, w + 1, kol, A);
			mnoznik = -1.0 * mnoznik;                      // kolejny mno¿nik
		}
		delete[] kol;                 // usuwamy zbêdn¹ ju¿ tablicê dynamiczn¹
		return rozwiniecie;                      // ustalamy wartoœæ funkcji
	}
}
double Matrix::deter()
{
	if (this->rows != this->cols)
	{
		std::cout << "Nie mozna policzyc wyznacznika" << std::endl;
		return -1;
	}
	int* WK = new int[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		WK[i] = i;
	}
	double wynik;
	wynik = deter(this->rows, 0, WK, this->values);
	delete[] WK;
	return wynik;
}
Matrix Matrix::transpose()
{
	Matrix wynik(this->cols, this->rows);
	for (int i = 0; i < wynik.rows; i++)
	{
		for (int j = 0; j < wynik.cols; j++)
		{
			wynik.values[i][j] = this->values[j][i];
		}
	}
	return wynik;
}
/*Matrix Matrix::reverse()
{
	double a = 1.0 / (this->values[0][0] * this->values[1][1] - this->values[0][1] * this->values[1][0]);
	Matrix wynik(this->rows, this->cols);
	wynik.values[0][0] = this->values[1][1];
	wynik.values[0][1] = -1.0 * this->values[0][1];
	wynik.values[1][0] = -1.0 * this->values[1][0];
	wynik.values[1][1] = this->values[0][0];
	wynik = wynik * a;
	return wynik;
}*/
Matrix Matrix::reverse()
{
	Matrix wynik(this->rows, this->cols);
	Matrix temp = *this;
	//if (this->deter() == 0)
	//{
	//	std::cout << "Nie mozna odwrocic macierzy" << std::endl;
	//	return wynik;
	//}
	//gaus jordan z czesciowym wyborem
	for (int i = 0; i < this->rows; i++)
	{
		wynik.values[i][i] = 1.0;
	}
	for (int i = 0; i < this->rows; i++)
	{
		int maxRow = i;
		for (int k = i + 1; k < this->rows; ++k) {//szukanie najwiekszej wartosci w kolumnie
			if (std::abs(temp.values[k][i]) > std::abs(temp.values[maxRow][i])) {
				maxRow = k;
			}
		}
		//zamaiana tak aby max byl na przekatnej
		if (maxRow != i)
		{
			double* temp1 = new double[this->cols];
			for (int j = 0; j < this->cols; j++)
			{
				temp1[j] = temp.values[i][j];
				temp.values[i][j] = temp.values[maxRow][j];
				temp.values[maxRow][j] = temp1[j];
				temp1[j] = wynik.values[i][j];
				wynik.values[i][j] = wynik.values[maxRow][j];
				wynik.values[maxRow][j] = temp1[j];
			}
		}
		//zerowanie elementow ponizej przekatnej
		double pivot = temp.values[i][i];
		for (int k = 0; k < this->rows; ++k) {
			temp.values[i][k] /= pivot;
			wynik.values[i][k] /= pivot;
		}
		//zerowanie elementow innych wierszy
		for (int j = 0; j < this->rows; ++j) {
			if (j != i) {
				double factor = temp.values[j][i];
				for (int k = 0; k < this->rows; ++k) {
					temp.values[j][k] -= factor * temp.values[i][k];
					wynik.values[j][k] -= factor * wynik.values[i][k];
				}
			}
		}
	}
	return wynik;
}
int Matrix::get_rows()
{
	return this->rows;
}
int Matrix::get_cols()
{
	return this->cols;
}