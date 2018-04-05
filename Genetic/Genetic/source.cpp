#include "population.h"
#include "state.h"
#include <iostream>
using namespace std;

int main(int argc,char** argv) {
	srand(time(0));
	int popsize = 20;
	int boardsize = 8;//don't do more than 8 it uses 8 gigs Ram?
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
	cin.get();
	cin.get();
}
