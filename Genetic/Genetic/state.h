#ifndef STATE_H
#define STATE_H
#include <random>
#include <ctime>
#include <iostream>

class State {
public:
	State();
	State(int* genes, int size);
	void setCost();
	int getCost();
	double getFitness();
	void setFitness(double fitness);
	void mutate();
	void print();
	State* crossover(State* partner);
private:
	int* m_genes;
	int m_size;
	int m_cost;
	double m_fitness;
};



#endif
