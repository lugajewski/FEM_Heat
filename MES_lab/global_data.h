#pragma once
#include<iostream>
class Global_data {
	friend class File_loader;
	double simulation_time;
	double simulation_step_time;
	double conductivity;
	double alfa;
	double tot;
	double initial_temp;
	double density;
	double specific_heat;
	int nodes_number;
	int elements_number;
public:
	void set_simulation_time(double simulation_time);
	double get_simulation_time();
	void set_simulation_step_time(double simulation_set_time);
	double get_simulation_step_time();
	void set_conductivity(double conductivity);
	double get_conductivity();
	void set_alfa(double alfa);
	double get_alfa();
	void set_tot(double tot);
	double get_tot();
	void set_initial_temp(double initial_temp);
	double get_initial_temp();
	void set_density(double density);
	double get_density();
	void set_specific_heat(double specific_heat);
	double get_specific_heat();
	void set_nodes_number(int nodes_number);
	int get_nodes_number();
	void set_elements_number(int elements_number);
	int get_elements_number();
	void read();
};
