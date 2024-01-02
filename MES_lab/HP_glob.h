#pragma once
#include"matrix.h"
class HP_glob
{
	friend class Element;
	friend class Node;
public:
	Matrix H;
	HP_glob(int nodes_number);
	HP_glob();
	void operator=(const HP_glob& hp_glob);
};

