//====================================================================
// Organism.cpp
// Implementation file for the organism's information
// Author: Drew Humphrey
// Date: April 2018
// CS307 Program 2
// This program is entirely my own work
//====================================================================

#pragma warning(disable:4996)

#include "Organism.h"
#include "Chromosome.h"
#include "GeneInfo.h"
#include "GeneticsSimDataParser.h"
#include <vector>

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Organism::Organism()
{
	m_vChromos = new vector<Chromosome>();
	m_parser = GeneticsSimDataParser::getInstance();
}

//-----------------------------------
// Destructor
//-----------------------------------
Organism::~Organism()
{
	m_parser = NULL;
	delete m_parser;
}

//-----------------------------------
//Set the scientific and common names
//-----------------------------------
void Organism::setNames(char *sciName, char *comName)
{
	strcpy(m_sScientificName, sciName);
	strcpy(m_sCommonName, comName);
}

//-----------------------------------
// Get the organism's scientific name
//-----------------------------------
char *Organism::getSciName()
{
	return m_sScientificName;
}

//-----------------------------------
// Get the organism's common name
//-----------------------------------
char *Organism::getCommonName()
{
	return m_sCommonName;
}

//-----------------------------------
//Add a chromosome to the collection of chromosomes
//-----------------------------------
void Organism::addChromosome(Chromosome *chromo)
{
	m_vChromos->push_back(*chromo);
}

//-----------------------------------
//Get the collection of chromosomes
//-----------------------------------
vector<Chromosome> *Organism::getChromosomes()
{
	return m_vChromos;
}


//-----------------------------------
// Print the organism's information
//-----------------------------------
void Organism::print()
{
	int counter = 1;
	cout << "Parent:" << endl;
	cout << "\tOrganism genus-species: " << this->getSciName() << endl;
	cout << "\tCommon name: " << this->getCommonName() << endl;
	cout << "\tChromosomes:" << endl;

	for(vector<Chromosome>::iterator itr = m_vChromos->begin(); itr != m_vChromos->end(); itr++)
	{
		cout << "\t\tChromosome " << counter << endl;
		itr->printGenes();
		counter++;
	}	
	cout << endl;
}