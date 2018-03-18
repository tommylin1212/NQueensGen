#include "population.h"
#include "state.h"
#include <iostream>
using namespace std;

int main(int argc,char** argv) {
	srand(time(0));
	Population* currentPop = new Population(2000,8,0.1);
	Population* temp;
	while (true) {
		if (currentPop->fitness()) {
			break;
		}
		else{
			temp = currentPop->doGeneration();
			delete currentPop;
			currentPop = temp;
		}
	}
	State* winner= currentPop->getWinner();
	winner->print();
}
