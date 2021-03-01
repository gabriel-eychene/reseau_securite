#include <stdio.h>
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

int countLettres( char * texte, int * nbLettres)
{
	int i;
	for( i = 0 ; i < 26 ; i++ )
	{
		nbLettres[i] = 0;
	}
	i = 0;
	while(texte[i] != '\0')
	{
		nbLettres[(int)(texte[i] - 'a')] += 1;
		i++;
	}
	return i - 1;
}

float friedman(char * texte)
{
	int nbLettres[26];
	int n = countLettres(texte, nbLettres);
	int i;
	float result = 0.0f;
	for( i = 0 ; i < 26 ; i++ )
	{
		result += ( (float)nbLettres[i] * (float)nbLettres[i] ) / ( (float)n * (float)n );
	}
	return result;
}

float keyLenght(char * texte)
{
	float kr = 0.0385f;
	float ke = 0.067f;
	float k = friedman(texte);
	return ( ke - kr ) / ( k - kr );
}

int main(int argc, char *argv[])
{
	char texte[BUFFER_SIZE];
	fgets(texte, BUFFER_SIZE, stdin);
	toLowerCase(texte);
	printf("%s\n", texte);
	float l = keyLenght(texte);
	printf("longueur de la clef l : %f\n", l);
	return 0;
}


