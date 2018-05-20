//====================================================================
// Main.cpp
// Main file to run the program
// Author: Drew Humphrey
// Date: March 2018
// CS307 Program 1
// This program is entirely my own work
//====================================================================

#include "Simulation.h"

int main()
{
	Simulation *sim = Simulation::getInstance();
	sim->runSimulation();
	sim->~Simulation();

	system("pause");

	return 0;
}