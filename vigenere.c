#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 128

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

int countLettres( char * texte, int ** nbLettres, int keySize)
{
	int i, j;
	for( j = 0 ; j < keySize ; j++ )
	{
		for( i = 0 ; i < 26 ; i++ )
		{
			nbLettres[j][i] = 0;
		}
	}
	i = 0;
	while(texte[i] != '\0')
	{
		nbLettres[ i  % keySize ][(int)(texte[i] - 'a')] += 1;
		i++;
	}
	return i - 1;
}

void freqAnalyse( char * texte, int keySize )
{
	int i, j, n;
	float freq;
	char * key = (char *)malloc((keySize + 1) * sizeof(char));
	char input[BUFFER_SIZE];
	int ** nbLettres = (int **)malloc(keySize * sizeof(int *));
	for( i = 0 ; i < keySize ; i++ )
	{
		nbLettres[i] = (int *)malloc( 26 * sizeof(int) );
	}
	n = countLettres(texte, nbLettres, keySize);

	printf("fréquence d'apparition des lettres :\n");
	for(i = 0 ; i < keySize ; i++ )
	{
		printf("position dans la clef : %d\n", i);
		for( j = 0 ; j < 26 ; j++ )
		{
			freq = (float)nbLettres[i][j] * (float)keySize * 100.0f / (float)n;
			printf("%c : %3.2f%%  ", (char)('a' + j), freq);
		}
		printf("\nEntrez la lettre correspondant au e : ");
		fgets(input, BUFFER_SIZE, stdin);
		key[i] = ((input[0] - 'e') % 26 + 'a' - 1);

	}

	key[keySize] = '\0';
	printf("la cle est : %s\n", key);

	decipher(texte, key);
	printf("texte dechiffre : %s\n", texte);

	free(key);
	for( i = 0 ; i < keySize ; i++ )
	{
		free(nbLettres[i]);
	}
	free(nbLettres);
}

int main(int argc, char *argv[])
{	
	char texte[BUFFER_SIZE];
	fgets(texte, BUFFER_SIZE, stdin);
	toLowerCase(texte);
	printf("%s\n", texte);

	char keySizeInput[BUFFER_SIZE];
	int keySize;
	fgets(keySizeInput, BUFFER_SIZE, stdin);
	keySize = atoi(keySizeInput);
	freqAnalyse(texte, keySize);

	return 0;
}


