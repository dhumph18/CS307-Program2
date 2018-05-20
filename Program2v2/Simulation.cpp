//====================================================================
// Simulation.cpp
// Implementation file to run the simulation
// Author: Drew Humphrey
// Date: April 2018
// CS307 Program 2
// This program is entirely my own work
//====================================================================

#pragma warning(disable:4996)

#include "Simulation.h"
#include "Organism.h"
#include "OrganismFactory.h"
#include "Breeder.h"
#include "GeneticsSimDataParser.h"
#include "GeneInfoFactory.h"
#include <string>

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Simulation::Simulation()
{
	cout << "Enter the name of the input file: ";
	cin >> m_sFileName;
	m_iNumOffspring = 0;
}

//-----------------------------------
// Destructor
//-----------------------------------
Simulation::~Simulation()
{

}

//-----------------------------------
// Runs the simulation
//-----------------------------------
void Simulation::runSimulation()
{
	cout << "\nRunning Simuation...\n" << endl;

	GeneInfoFactory *geneFact = GeneInfoFactory::getInstance();
	m_vGenes = geneFact->buildGene(m_sFileName);

	
	OrganismFactory *orgFact = OrganismFactory::getInstance();
	Organism *parent1 = orgFact->createOrganism(1);
	Organism *parent2 = orgFact->createOrganism(2);

	parent1->print();
	parent2->print();

	cout << "How many offspring do you want to generate?\n-->";
	cin >> m_iNumOffspring;
	
	Breeder *breeder = new Breeder();
	breeder->breed(parent1, parent2, m_iNumOffspring);
	breeder->print();
}

//-----------------------------------
// Get the singleton instance
//-----------------------------------
Simulation *Simulation::getInstance()
{
	static Simulation *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new Simulation();
	}
	return theInstance;
}

//-----------------------------------
// Return the master gene corresponding to the given allele 
//-----------------------------------
GeneInfo *Simulation::getMasterGene(char allele)
{
	for(GeneInfo &master : m_vGenes)
	{
		if(allele == master.getDomSymbol() || allele == master.getRecSymbol())
			return &master;
	}

	return NULL;
}

