#include <stdio.h>
#define BUFFER_SIZE 128

void toLowerCase(char * texte)
{
	int i = 0;
	int j = 0;
	char resultat[BUFFER_SIZE];
	while(texte[i] != '\0')
	{
		if(texte[i] >= 'a' && texte[i] <= 'z' )
		{
			resultat[j] = texte[i];
			j++;
		}
		else if(texte[i] >= 'A' && texte[i] <= 'Z' )
		{
			resultat[j] = texte[i] + 32;
			j++;
		}
		i++;
	}
	resultat[j] = '\0';
	i = 0;
	while(resultat[i] != '\0')
	{
		texte[i] = resultat[i];
		i++;
	}
	texte[i] = '\0';
}

int main(int argc, char *argv[])
{
	char texte[BUFFER_SIZE];
	fgets(texte, BUFFER_SIZE, stdin);
	toLowerCase(texte);
	printf("%s\n", texte);
	return 0;
}
