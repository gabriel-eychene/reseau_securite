#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

char** ajout(char** tab, char* mot, int nbTypeOccur){
	tab[nbTypeOccur] = malloc(strlen(mot)*sizeof(char));
	for(int i=0; i<strlen(mot); i++){
		tab[nbTypeOccur][i] = mot[i];
	}
}

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

void occurrence(char message[BUFFER_SIZE], int windowSizeStart){
	int windowStart = 0;
	int windowSize = windowSizeStart;
	int nbOccur = 0;
	int diff;
	int nbTypeOccur = 0;

	char** typeOccur;
	typeOccur = malloc(strlen(message) * sizeof(char));
	if(typeOccur == NULL){
		exit(0);
	}

	char* mot;
	mot = malloc(windowSize * sizeof(char));
	if(mot == NULL){
		exit(0);
	}

	while((windowStart + windowSize) < strlen(message)){

		nbOccur = 0;
		for(int i = windowSize + windowStart; i<= strlen(message) - windowSize; i++){
			diff = 0;
			for(int j=0; j<windowSize; j++){
				if(message[windowStart + j] != message[i + j]){
					diff = 1;
				}
			}
			if(diff == 0){
				nbOccur++;
			}
		}
		
		if(nbOccur > 0){

			
			for(int l=0; l<windowSize; l++){
				mot[l] = message[l + windowStart];
			}

			if(!isContain(typeOccur, mot, nbTypeOccur)){

				ajout(typeOccur, mot, nbTypeOccur);
				nbTypeOccur++;

				for(int k=0; k<windowSize; k++){
					printf("%c", message[k + windowStart]);
				}

				printf(" trouvé %d fois.\n", nbOccur + 1);
			}
			windowSize++;

			for(int m=0; m<windowSize; m++){
				mot[m] = '\0';
			}
		}
		else{
			windowStart++;
			windowSize = windowSizeStart;
		}
	}

	/*for(int i=0; i<strlen(message); i++){
		free(typeOccur[i]);
	}*/
	free(typeOccur);
	free(mot);
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



