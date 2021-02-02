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


int main(int argc, char *argv[])
{
	/*char texte[BUFFER_SIZE];
	scanf("%s", texte);
	printf("%s\n", texte);*/
	char test, res, key = 'g';
	scanf("%c\n", &test);
	res = convertion(test, key);
	printf("%c\n", res);
	return 0;
}


