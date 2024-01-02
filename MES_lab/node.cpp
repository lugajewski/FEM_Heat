#pragma once
#include "node.h"

void Node::set_number(int number)
{
	this->number = number;
}
int Node::get_number()
{
	return this->number;
}
void Node::set_x(double x)
{
	this->x = x;
}
double Node::get_x()
{
	return this->x;
}
void Node::set_y(double y)
{
	this->y = y;
}
double Node::get_y()
{
	return this->y;
}
int Node::get_BC()
{
	return this->BC;
}
void Node::set_BC(int BC)
{
	this->BC = BC;
}
void Node::read()
{
	std::cout << "Wezel nr:" << number << " x:" << x << " y:" << y << std::endl;
}
void Node::operator=(const Node& node)
{
	this->number = node.number;
	this->x = node.x;
	this->y = node.y;
	this->BC = node.BC;
}