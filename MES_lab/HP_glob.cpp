#pragma once 
#include "HP_glob.h"

HP_glob::HP_glob(int nodes_number)
{
	H.resize(nodes_number, nodes_number);
}
HP_glob::HP_glob()
{

}
void HP_glob::operator=(const HP_glob& hp_glob)
{
	this->H = hp_glob.H;
}