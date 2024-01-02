#pragma once
#include"global_data.h"

void Global_data::set_simulation_time(double simulation_time)
{
	this->simulation_time = simulation_time;
}
double Global_data::get_simulation_time()
{
	return this->simulation_time;
}
void Global_data::set_simulation_step_time(double simulation_step_time)
{
	this->simulation_step_time = simulation_step_time;
}
double Global_data::get_simulation_step_time()
{
	return this->simulation_step_time;
}
void Global_data::set_conductivity(double conductivity)
{
	this->conductivity = conductivity;
}
double Global_data::get_conductivity()
{
	return this->conductivity;
}
void Global_data::set_alfa(double alfa)
{
	this->alfa = alfa;
}
double Global_data::get_alfa()
{
	return this->alfa;
}
void Global_data::set_tot(double tot)
{
	this->tot = tot;
}
double Global_data::get_tot()
{
	return this->tot;
}
void Global_data::set_initial_temp(double initial_temp)
{
	this->initial_temp = initial_temp;
}
double Global_data::get_initial_temp()
{
	return this->initial_temp;
}
void Global_data::set_density(double density)
{
	this->density = density;
}
double Global_data::get_density()
{
	return this->density;
}
void Global_data::set_specific_heat(double specific_heat)
{
	this->specific_heat = specific_heat;
}
double Global_data::get_specific_heat()
{
	return this->specific_heat;
}
void Global_data::set_nodes_number(int nodes_number)
{
	this->nodes_number = nodes_number;
}
int Global_data::get_nodes_number()
{
	return this->nodes_number;
}
void Global_data::set_elements_number(int elements_number)
{
	this->elements_number = elements_number;
}
int Global_data::get_elements_number()
{
	return this->elements_number;
}
void Global_data::read()
{
	std::cout << "Dane globalne :" << std::endl;
	std::cout << simulation_time << " " << std::endl;
	std::cout << simulation_step_time << " " << std::endl;
	std::cout << conductivity << " " << std::endl;
	std::cout << alfa << " " << std::endl;
	std::cout << tot << " " << std::endl;
	std::cout << initial_temp << " " << std::endl;
	std::cout << density << " " << std::endl;
	std::cout << specific_heat << " " << std::endl;
	std::cout << nodes_number << " " << std::endl;
	std::cout << elements_number << " " << std::endl;
}