#include "population.h"
#include <iostream>


using namespace std;

Population::Population(int size,State** members, double mutation){
	m_size = size;
	m_members = members;
	m_mutation = mutation;
}

Population::Population(int popSize,int boardSize,double mutation){
	m_size = popSize;
	m_mutation = mutation;
	m_members = new State*[m_size];
	int* tempGenes = new int[boardSize];
	for (int i = 0; i < m_size; i++) {
		for (int j = 0; j < boardSize; j++) {
			tempGenes[j] = rand() % boardSize;
		}
		m_members[i] = new State(tempGenes, boardSize);
	}
}

Population::~Population(){
	for (int i = 0; i < m_size; i++) {
		delete m_members[i];
	}
}

bool Population::evaluate(){
	m_total = 0;
	for (int i = 0; i < m_size; i++) {
		if (m_members[i]->getCost() == 0) {
			m_winner = m_members[i];
			return true;
		}
		m_total += m_members[i]->getCost();
	}
	return false;
}

bool Population::fitness(){
	if (evaluate()) {
		return true;
	}
	for (int i = 0; i < m_size; i++) {
		double fitness=(m_members[i]->getCost()) / m_total;
		m_members[i]->setFitness(fitness);
	}
	return false;
}

State * Population::getWinner(){
	return m_winner;
}

Population * Population::doGeneration(){
	State** newGen = new State*[m_size];
	for (int i = 0; i < m_size; i++) {
		newGen[i] = selectMember()->crossover(selectMember());
		if (((rand() % 1000) / 1000.0) < m_mutation) {
			newGen[i]->mutate();
		}
	}
	return new Population(m_size, newGen, m_mutation);
}

State * Population::selectMember(){
	while (true) {
		int index = rand() % m_size;
		double probability = (rand() % 1000) / 1000.0;
		if (m_members[index]->getFitness() < probability) {
			return m_members[index];
		}
	}
}



