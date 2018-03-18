#ifndef POPULATION_H
#define POPULATION_H
#include "state.h"
class Population {
public:
	Population(int size,State** members,double mutation);
	Population(int size,int boardSize,double mutation);
	~Population();
	bool evaluate();
	bool fitness();
	State* getWinner();
	Population* doGeneration();
	State* selectMember();
private:
	State** m_members;
	int m_size;
	double m_total;
	State* m_winner;
	double m_mutation;
};

#endif