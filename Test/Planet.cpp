#include "Planet.h"
#include <iostream>


Planet::Planet()
{
	m_planet = new Renderable();
	//this->atuch_children(m_planet);
}


void Planet::Init()
{
	//m_planet->init_sprite();
	std::cout << "init" << std::endl;

}
void Planet::Update()
{

}
void Planet::Close()
{

}

Planet::~Planet()
{
}
