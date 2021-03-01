#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

//Méthode permettant d'ajouter un mot au tableau contenant les différentes occurences
char** ajout(char** tab, char* mot, int nbTypeOccur){
	tab[nbTypeOccur] = malloc(strlen(mot)*sizeof(char));
	for(int i=0; i<strlen(mot); i++){
		tab[nbTypeOccur][i] = mot[i];
	}
}

//Methode permettant de tester si le mot appartient au tablau des occurences déjà traitées
int isContain(char** tab, char* mot, int size){
	int res;
	for(int i=0; i<size; i++){
		res = 1;
		if(strlen(tab[i]) != strlen(mot)){
			res = 0;
		}
		else{
			for(int j=0; j<size; j++){
				if(mot[j] != tab[i][j]){
					res = 0;
				}
			}
		}
		if(res){
			break;
		}
	}
	return res;
}

void tabContain(int* tab){

}

void gap(int* tab, int nbElem){

	//Tableau contenant les diviseurs communs entre les écarts
	int** dividers;
	dividers = malloc(nbElem * sizeof(int));
	if(dividers == NULL){
		exit(0);
	}
	printf("----\n");
	dividers[5] = tab;
	printf("tab[5] = %d\n", tab[5]);
	printf("----\n");

	//Pour chaque écart, on calcul ses diviseurs
	for(int i=0; i<nbElem; i++){

		printf("i = %d\n", i);

		//Ajout de la valeur de l'écart ainsi que le nombre de diviseurs dans les premières colonnes de la ligne i
		dividers[i] = malloc(2*sizeof(int));
		dividers[i][0] = tab[i];
		dividers[i][1] = 0;

		//Ajout des diviseur de l'écart sur le reste des colonnes de la ligne i
		for(int j=1; j<=tab[i]; j++){
			if(tab[i]%j == 0){
				//dividers[i] = realloc(dividers[i], sizeof(int));
				dividers[i][dividers[i][1]+2] = j;
				dividers[i][1]++;
			}
		}
	}

	for(int i=0; i<nbElem; i++){
		printf("Ecart[%d]: ", dividers[i][0]);
		for(int j=0; j<dividers[i][1]; j++){
			printf("[%d]", dividers[i][j+2]);
		}
		printf("\n");
	}

	for(int i=0; i<nbElem; i++){
		free(dividers[i]);
	}
	free(dividers);
}

void occurrence(char message[BUFFER_SIZE], int windowSizeStart){
	int windowStart = 0;
	int windowSize = windowSizeStart;
	int nbOccur = 0;
	int diff;
	int nbTypeOccur = 0;

	//Allocation mémoire
	//Tableau 2d contenant les différentes répétitions
	char** typeOccur;
	typeOccur = malloc(strlen(message) * sizeof(char));
	if(typeOccur == NULL){
		exit(0);
	}

	//Variable réprésentant le mot de la fenêtre
	char* mot;
	mot = malloc(windowSize * sizeof(char));
	if(mot == NULL){
		exit(0);
	}

	//Tableau contenant les différents écarts entre les répétitions
	int* ecartOccur;
	ecartOccur = malloc(sizeof(int));
	if(ecartOccur == NULL){
		exit(0);
	}
	int nbElem = 0;

	while((windowStart + windowSize) < strlen(message)){

		//Nombre de répétition initialisé à 1
		nbOccur = 1;

		//On parcours le reste du texte (à partir du premier élément après de la fenêtre)
		for(int i = windowSize + windowStart; i<= strlen(message) - windowSize; i++){

			//Différence entre le mot de la fenêtre et celui testé actuellement
			diff = 0;

			//On test chaque lettre de la fenêtre
			for(int j=0; j<windowSize; j++){
				if(message[windowStart + j] != message[i + j]){
					diff = 1;
				}
			}
			//Si pas de différence, on a une occurence suplémentaire
			if(diff == 0){

				//On sauvgarde l'espace entre les deux séquences
				ecartOccur = realloc(ecartOccur, sizeof(int));
				if(ecartOccur == NULL){
					exit(0);
				}
				ecartOccur[nbElem] = i - windowStart;
				nbElem++;

				//Incrémentation du nombre d'occurence
				nbOccur++;
			}
		}
		
		//Si une ou plusieurs occurrences ont été trouvé
		if(nbOccur > 1){

			//Initialisation de la variable "mot" qui contient l'occurrence répétée
			for(int l=0; l<windowSize; l++){
				mot[l] = message[l + windowStart];
			}

			//On test si on a déjà comptabilisé ce type d'occurrence.
			if(!isContain(typeOccur, mot, nbTypeOccur)){

				ajout(typeOccur, mot, nbTypeOccur);
				nbTypeOccur++;

				for(int k=0; k<windowSize; k++){
					printf("%c", message[k + windowStart]);
				}

				printf(" trouvé %d fois.\n", nbOccur);
			}
			windowSize++;

			//Remise à 0 de la varialbe "mot"
			for(int m=0; m<windowSize; m++){
				mot[m] = '\0';
			}
		}
		//Sinon on remet la taille de la fenêtre à celle de base, et on déplace le début de celle-ci
		else{
			windowStart++;
			windowSize = windowSizeStart;
		}
	}
	//gap(ecartOccur, nbElem);

	for(int i = 0; i<nbElem; i++){
		printf("[%d]", ecartOccur[i]);
	}
	printf("\n");

	//Libération de mémoire
	for(int i=0; i<nbTypeOccur; i++){
		free(typeOccur[i]);
	}
	free(typeOccur);
	free(mot);
	free(ecartOccur);
}

int main(int argc, char *argv[])
{
	/*char texte[BUFFER_SIZE];
	scanf("%s", texte);
	printf("Size = %d\n", (int)strlen(texte));
	occurrence(texte, 3);*/

	//Exemple du TP:
	occurrence("abcdefghijklmnopqrstuvwxyzabcdmnoabc",3);
	return 0;
}



