#include<iostream>

#include"file_loader.h"
#include"grid.h"
#include"global_data.h"
#include"element.h"
#include"node.h"
#include"universal_element.h"

#define NODES 2

int main()
{
	File_loader f1;
	f1.load_data_from_file("Test2_4_4.txt");
	Grid grid;
	grid = f1.get_grid();
	Global_data glo;
	glo = f1.get_global_data();
	Matrix H_Global(glo.get_nodes_number(), glo.get_nodes_number());
	Matrix C_Global(glo.get_nodes_number(), glo.get_nodes_number());
	Matrix P_Global(glo.get_nodes_number(), 1);
	Element* elementy = new Element[glo.get_elements_number()];
	elementy = f1.get_elements();
	for(int i=0;i<glo.get_elements_number();i++)
	{
		elementy[i].set_nodes_number(NODES);
		elementy[i].set_k(glo.get_conductivity());
		elementy[i].set_alfa(glo.get_alfa());
		elementy[i].set_initial_temp(glo.get_tot());
		elementy[i].set_H_glob(&H_Global);
		elementy[i].set_P_glob(&P_Global);
		elementy[i].set_C_glob(&C_Global);
		elementy[i].set_cp(glo.get_specific_heat());
		elementy[i].set_ro(glo.get_density());
		elementy[i].calculate();
		//elementy[i].read_calculations();
	}
	Universal_element u1(2);
	double tal = glo.get_simulation_step_time();
	Matrix t0(16, 1);
	t0 = glo.get_initial_temp();
	//u1.read();
	//H_Global.read();
	//P_Global.read();
	Matrix H_temp = H_Global;
	Matrix P_temp = P_Global;
	H_temp = H_Global + (C_Global * (1.0/tal));
	H_temp.read();
	P_temp = ((C_Global * (1.0 / tal)) * t0) + (P_Global*1.0);
	//C_Global.read();
	Matrix A = H_temp.reverse();
	std::cout << std::endl << std::endl;
	//A.read();
	//P_Global.read();
	//P_temp.read();
	Matrix t1 =A * P_temp;
	t1.read();
	//std::cout<<H_Global.deter(); //nie da sie obliczyc wyznacznika macierzy h_glob 
	//Matrix B = H_Global.reverse();
	//B.read();
	//Matrix A = B * P_Global;
	//A.read();
	
	return 0;
}