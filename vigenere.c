#include <stdio.h>
#define BUFFER_SIZE 128

char convertion(char letterToConvert, char keyLetter){
	printf("Lettre à convertir: %c\n", letterToConvert);
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

int main(int argc, char *argv[])
{
  char texte[BUFFER_SIZE];
	fgets(texte, BUFFER_SIZE, stdin);
	toLowerCase(texte);
	printf("%s\n", texte);
  
	char test, res, key = 'g';
	scanf("%c\n", &test);
	res = convertion(test, key);
	printf("%c\n", res);

	return 0;
}


