#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

char convertion(char letterToConvert, char keyLetter){
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int keyNum, letterNum;
	for(int i = 0; i <= 25; i++){
		if(alphabet[i] == keyLetter){
			keyNum = i;
		}
	}
	for(int i = 0; i <= 25; i++){
		if(alphabet[i] == letterToConvert){
			letterNum = i;
		}
	}
	
	return alphabet[(letterNum + keyNum + 1)%26];
}

void toLowerCase(char * texte)
{
	int i = 0;
	int j = 0;
	while(texte[i] != '\0')
	{
		if(texte[i] >= 'a' && texte[i] <= 'z' )
		{
			texte[j] = texte[i];
			j++;
		}
		else if(texte[i] >= 'A' && texte[i] <= 'Z' )
		{
			texte[j] = texte[i] + 32;
			j++;
		}
		i++;
	}
	texte[j] = '\0';
}

void decipher(char * texte, char * clef)
{
	int i = 0;
	int j = 0;
	char clefInverse;
	while(texte[i] != '\0')
	{
		clefInverse = 26 - ( clef[j] - 96) + 96;
		texte[i] = convertion(texte[i], clefInverse);
		i++;
		j++;
		if(clef[j] == '\0')
		{
			j = 0;
		}
	}
}

char * probableWord(char * texte, char * mot, int position)
{
	int i = 0;
	while( mot[i] != '\0')
	{
		i++;
	}
	char * sousTexte = (char *)malloc(( i + 1 ) * sizeof(char) );
	i = 0;
	while( mot[i] != '\0')
	{
		sousTexte[i] = texte[i + position];
		i++;
	}
	sousTexte[i] = '\0';
	decipher(sousTexte, mot);
	return sousTexte;
}

int main(int argc, char *argv[])
{
	char texte[BUFFER_SIZE];
	char mot[BUFFER_SIZE];
	int position;
	printf("Entrez le message a dechiffrer : \n");
	fgets(texte, BUFFER_SIZE, stdin);
	printf("Entrez le mot probable : \n");
	fgets(mot, BUFFER_SIZE, stdin);
	printf("Entrez la position du mot probable : \n");
	scanf("%d\n", &position);
	toLowerCase(texte);
	toLowerCase(mot);
	printf("Texte : %s\nMot : %s\n", texte, mot );
	char * motDechiffre = probableWord(texte, mot, position);
	printf("Mot dechiffre : %s\n", motDechiffre);
	free(motDechiffre);

	return 0;
}


