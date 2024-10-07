#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 0

using namespace std;

class Cell{
	private:
		float surIndex;
	public:
		Cell() {
			this->surIndex = rand() % 100;	
		}

		Cell(int num){
			this->surIndex = num;	
		}

		void mutate(){
			this->surIndex += ( rand() % 3 ) - 1 ;
		}

		Cell * reproduce(){
			Cell * child = new Cell(this->surIndex);
			child->mutate();

			return child;
		}

		void showSur(){
			cout << this->surIndex;
		}
};

class Enviroment{
	private :
		int size;
		Cell * population;
	
	public :
		Enviroment(){
			this->size = 0;
			this->population = (Cell *)malloc(sizeof(Cell));
		}

		void addCell(Cell * being){
			this->population[this->size] = *being;
			this->size ++;
			this->population = (Cell *)realloc(this->population, sizeof(Cell) * (this->size + 1));
		}

		void showAllSur(){
			for(int i=0;i<this->size;i++){
				this->population[i].showSur();
				cout << " - ";
			}
		}

		Cell * findParent(){
			int choice = rand() % this->size;
			return this->population[choice].reproduce();
		}
};

int main(){
	srand (time(NULL));
	
	Enviroment* earth = new Enviroment;
	Cell * first = new Cell;
	earth->addCell(first);

	for(int i=0;i<200; i++){
		earth->addCell(earth->findParent());
		earth->showAllSur();
		printf("\n");
	}

	return SUCCESS;
}
