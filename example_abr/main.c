#include <stdio.h>
#include <string.h>

typedef struct _noeud
{      int val ; // valeur stockee
       struct _noeud *  fg, * fd; // pointeurs vers les noeuds fils 
} NOEUD, * ABR ;

void exo1(){
	// Donner le schéma de l’arbre obtenu en insérant la suite de valeurs 
	//{2,1,8,6,7,3,9,5} dans cet ordre dans l’arbre a.
	

}
//Exo 2
ABR createABRNode(int valeur){
	ABR newNode = NULL;
	
	newNode = (ABR) malloc(sizeof(struct _noeud));
	
	newNode -> val = valeur;
	newNode -> fg = NULL;
	newNode -> fd = NULL;
	return newNode;
	
}
//Exo 3
ABR insertInABR(int value, ABR currentNode){
	
	//printf("Inserting value:\n");
	if(currentNode == NULL){
		//printf("Creating node\n");
		return createABRNode(value);
	}else{
		if(currentNode-> val > value){
			currentNode -> fg =  insertInABR(value, currentNode -> fg);
			}
		else{
			currentNode -> fd =   insertInABR(value, currentNode -> fd);
		}
		return currentNode;
		}
	
}
//Exo 4
void afficherABR(ABR currentNode){
	if(currentNode != NULL){
			afficherABR(currentNode->fg);
			printf("value %d\n", currentNode -> val);
			afficherABR(currentNode->fd);
		}
	}
// t as the '-' from the previous levels.
void afficherABR_forme(ABR currentNode, char * t){
	if(currentNode != NULL){
			char  tnew [20] = "-";
			strcat(tnew, t);
			afficherABR_forme(currentNode->fg, tnew);
			printf("%s %d\n", t, currentNode -> val);
			afficherABR_forme(currentNode->fd, tnew);
		}
	}
	
// exo  5
void afficherABR_Decro(ABR currentNode){
	if(currentNode != NULL){
			afficherABR_Decro(currentNode->fd);
			printf("value %d\n", currentNode -> val);
			afficherABR_Decro(currentNode->fg);
		}
	}

// Exo 7Ecrire une fonction qui recherche la valeur n 
//dans a et renvoie 1 si trouvée, 0 sinon

int rechercheABR(ABR currentNode, int valueToSearch){
		if(currentNode == NULL){
				return 0;
		}
		else{
			if(currentNode-> val == valueToSearch){
				return 1;
			}else if(currentNode-> val > valueToSearch){
				return rechercheABR(currentNode-> fg, valueToSearch);
				}else{
					return rechercheABR(currentNode-> fd, valueToSearch);
					}
			}
}

int rechercheABRLevel(ABR currentNode, int valueToSearch, int level){
		if(currentNode == NULL){
				return 0;
		}
		else{
			if(currentNode-> val == valueToSearch){
				printf("Value %d Found at level %d\n", valueToSearch, level);
				return 1;
			}else if(currentNode-> val > valueToSearch){
				return rechercheABRLevel(currentNode-> fg, valueToSearch, level + 1 );
				}else{
					return rechercheABRLevel(currentNode-> fd, valueToSearch, level + 1);
					}
			}
}


NOEUD* searchPlusPetit(ABR currentNode){
	if(currentNode == NULL){
		return NULL;
	}
	
	if(currentNode -> fg == NULL){
		return currentNode;
		}
	else{
		return searchPlusPetit(currentNode -> fg);
		}
}
//Ecrire une fonction qui renvoie la somme et le nombre 
//de valeurs contenues dans a.

void computeMetrics(ABR currentNode, int * sum, int * nombre){
	
	if (currentNode == NULL){
		*sum = 0;
		*nombre = 0;
	}else{
			int sumG = 0;
			int nombreG = 0;
			computeMetrics(currentNode -> fg, &sumG, &nombreG);
			
			int sumD = 0;
			int nombreD = 0;
			
			computeMetrics(currentNode -> fd, &sumD, &nombreD);
			
			//Summary of results 
			*sum = sumG + sumD + currentNode -> val;
			*nombre = nombreG + nombreD + 1;
	}
	
}

//Ecrire une fonction qui renvoie la moyenne des valeurs contenues dans a

float computeMoyenne(ABR currentNode){
	
	int sumTotal = 0;
	int nombreTotal = 0;
	
	computeMetrics(currentNode, &sumTotal, &nombreTotal);
	
	return sumTotal / nombreTotal;
}
//Exo 12
int hauteur(ABR currentNode){
	if(currentNode == NULL)
		return 0;
	else{
			int hauteurG = hauteur(currentNode -> fg);
			int hauteurD = hauteur(currentNode -> fd);
			
			if( hauteurG > hauteurD)
				return 1 + hauteurG;
			else{
				return 1 + hauteurD;
				}
			
	}
}

int supp_max(ABR * a)
{	int res;
	if ((*a)->fd == NULL) // pas de fils droit max trouvé
	{	res = (*a)->val; 
		*a = (*a)->fg;
	} else	res = supp_max(&((*a)->fd)); // on descend à droite
	return res ;
}

ABR suppression(int elementToRemove, ABR a)
{  if (a)
	{ if (elementToRemove < a->val) 
		a->fg = suppression(elementToRemove, a->fg);
	else if (elementToRemove > a->val)	
			  a->fd = suppression(elementToRemove, a->fd);
    		else   // elementToRemove == val(a)
  				if (a->fg == NULL) a = a->fd;
  				else	if (a->fd == NULL) a = a->fg;
 					else a->val = supp_max(&(a->fg));
	}
  return a;		
}


int main(int argc, char **argv)
{
	printf("TD 4 ABR: \n");
	
	ABR a=NULL; // equivalent:  struct _noeud * a = NULL;
	///  exo 1: {4,2,1,8,6,7,3,9,5}
	a = insertInABR(4, a);
	a = insertInABR(2, a);
	a = insertInABR(1, a);
	a = insertInABR(8, a);
	a = insertInABR(6, a);
	a = insertInABR(7, a);
	a = insertInABR(3, a);
	a = insertInABR(9, a);
	a = insertInABR(5, a);
	printf("Exo 4: printing ABR crois:\n");
	afficherABR(a);
	
	
	printf("Exo 5: printing ABR decro:\n");
	afficherABR_Decro(a);
	
	printf("Exo 6: print format\n");
	
	afficherABR_forme(a, "");
	
	printf("Exo 7: search\n");
	
	int valueToSearch = 10;
	int resultSearch = rechercheABR(a, valueToSearch);
		printf("Exists value %d: %d\n", valueToSearch, resultSearch);
		
	valueToSearch = 5;
	resultSearch = rechercheABR(a, valueToSearch);
	printf("Exists value %d: %d\n", valueToSearch, resultSearch);
	
	printf("Exo 8: search min\n");
	
	NOEUD* pPetit = searchPlusPetit(a);
	if (pPetit != NULL){
		printf("Value min: %d \n", pPetit->val);
	}else{
		printf("No value on ABR");
	}
	
	printf("exo 9\n");
	
	int sumTotal = 0;
	int nombreTotal = 0;
	
	computeMetrics(a, &sumTotal, &nombreTotal);
	printf("sum %d , nombre %d\n", sumTotal, nombreTotal);
	
	float moy = computeMoyenne(a);
	printf("Moyenne %f\n", moy);
	
	//Exo 11:
	valueToSearch = 5;
	int initialLevel = 0;
	resultSearch = rechercheABRLevel(a, valueToSearch, initialLevel);
	printf("Exists value %d: %d\n", valueToSearch, resultSearch);
	
	
	valueToSearch = 2;
	initialLevel = 0;
	resultSearch = rechercheABRLevel(a, valueToSearch, initialLevel);
	printf("Exists value %d: %d\n", valueToSearch, resultSearch);
	
	//
	int h = hauteur(a);
	printf("Hauteur %d\n", h);
	
	int elementToRemove = 3;
	printf("Removing\n");
	printf("Before removing\n");
	afficherABR_forme(a, "");
	a = suppression(elementToRemove, a);
	printf("After removing %d\n", elementToRemove);
	afficherABR_forme(a, "");
	
	elementToRemove = 8;
	a = suppression(elementToRemove, a);
	printf("After removing %d\n", elementToRemove);
	afficherABR_forme(a, "");
	
	return 0;
}
