#include <stdio.h>

///
#define MAX 20
#define VALUE_NULL -1

typedef float TAB[MAX];

typedef  struct {
	TAB values;	// pile d'éléments
	int card; // nombre d'éléments dans la pile
} PILE;

//p ; p doit etre vide en sortie de cette fonction.
void init(PILE *p){
   
	p->card = 0;
	for (int i =0; i< MAX; i++){
			p->values[i] = VALUE_NULL;
		}
	
}
//renvoie 1 si p ne contient rien, 0 sinon
int estVide(PILE p){
	
	if(p.card == 0){
		return 1;
	}
	else{
			return 0;
			}
	
}


int main(int argc, char **argv)
{
	printf("TD 3 Exo 2 Files et piles: \n");
	
	PILE myPile;
	myPile.card;
	myPile.values;
	
	init(&myPile);
	
	//Dont use -> because myPile is not a pointer
	//myPile is a struct so for this reason we use . to access to its values
	printf("Size of pile: %d \n", myPile.card);
	
	int isEmpty = estVide(myPile);
	
	printf("is Empty? %d", isEmpty);
	
	return 0;
	
	
}
