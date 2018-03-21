#include "population.h"
#include "state.h"
#include <iostream>
using namespace std;

int main(int argc,char** argv) {
	srand(time(0));
	int popsize = 2000;
	int boardsize = 8;
	int generations = 1;
	Population* currentPop = new Population(popsize,boardsize,0.1);
	Population* temp;
	while (true) {
		if (currentPop->fitness()) {
			break;
		}
		else{
			generations++;
			temp = currentPop->doGeneration();
			delete currentPop;
			currentPop = temp;
		}
	}
	State* winner= currentPop->getWinner();
	winner->print();
	cout << "Generations: " << generations << endl << "Individuals: " << generations*popsize<<endl;
	
}
