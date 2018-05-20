//====================================================================
// Simulation.h
// Interface file to run the simulation
// Author: Drew Humphrey
// Date: April 2018
// CS307 Program 2
// This program is entirely my own work
//====================================================================

#ifndef SIMUTATION_H
#define SIMUTATION_H

#include <vector>
#include "GeneInfo.h"

class Simulation
{
	private:
		int m_iNumOffspring;		//Number of offspring to be produced
		char m_sFileName[64];		//Name of input file
		GeneticsSimDataParser *parser;
		vector<GeneInfo> m_vGenes;	//Collection of master genes
		Simulation();				//Constructor

	public:
		~Simulation();				//Destructor
		void runSimulation();		//Runs the simulation
		static Simulation *getInstance(); //Get the singleton instance
		GeneInfo *getMasterGene(char allele); //Return the master gene corresponding to the given allele
};
#endif