#include "state.h"


using namespace std;
State::State(){
	m_size = -1;
	m_cost = -1;
	m_fitness = -1;
	m_genes = NULL;
	
}
State::~State(){
	delete[] m_genes;
}
State::State(int * genes, int size){
	this->m_genes = genes;
	this->m_size = size;
	this->setCost();
}

void State::setCost(){
	m_cost = 0;
	int offset;
	for (int row = 0; row < m_size; row++) {
		for (int column = row + 1; column < m_size; column++) {
			if (m_genes[row]==m_genes[column]) {
				m_cost++;//same row
			}
			offset = column - row;
			if ((m_genes[row] == (m_genes[column] - offset)) || (m_genes[row] == (m_genes[column] + offset))) {
				m_cost++;//diagonals
			}
		}
	}
}

int State::getCost(){
	return m_cost;
}

double State::getFitness(){
	return m_fitness;
}

void State::setFitness(double fitness){
	m_fitness = fitness;
}

void State::mutate(){
	int index = rand() % m_size;
	int number = rand() % m_size;
	m_genes[index] = number;
}

void State::print(){
	for (int i = 0; i < m_size; i++) {//row
		cout << '\n';
		for (int j = 0; j < m_size; j++) {//col
			if (m_genes[j] == i) {
				cout << "Q ";
			}
			else {
				cout << "X ";//Not Queen
			}
		}
	}
	cout << '\n';
}

State* State::crossover(State* partner){
	int* childGenes = new int[m_size];
	int index = rand() % m_size;
	for (int i = 0; i < m_size; i++) {
		if (i < index) {
			childGenes[i] = (this->m_genes)[i];
		}
		else {
			childGenes[i] = (partner->m_genes)[i];
		}
	}
	return new State(childGenes,m_size);
}


