#pragma once
#include<iostream>
class Matrix {
	double** values;
	int rows;
	int cols;
public:
	Matrix();
	//~Matrix();
	Matrix(int rows, int cols);
	double deter();
	double deter(int n, int w, int* WK, double** A);
	Matrix transpose();
	Matrix reverse();
	void set_values(int row,int col,int value);
	void set_values(int row, int col, float value);
	void set_values(int row, int col, double value);
	void add_values(int row, int col, double value);
	double get_value(int row, int col);
	void read();
	void resize(int rows, int cols);
	int get_rows();
	int get_cols();
	
	void operator=(const int& number);
	void operator=(const float& number);
	void operator=(const double& number);
	void operator=(const Matrix& matrix);
	Matrix operator+(const int& number);
	Matrix operator+(const float& number);
	Matrix operator+(const double& number);
	Matrix operator+(const Matrix& matrix);
	Matrix operator*(const int& number);
	Matrix operator*(const float& number);
	Matrix operator*(const double& number);
	Matrix operator*(const Matrix& matrix);
};