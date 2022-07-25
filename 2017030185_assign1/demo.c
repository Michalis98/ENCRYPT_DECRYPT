#include <stdio.h>
#include <stdlib.h>
#include "simple_crypto.h"


void main(){
	
	char input[10000];
	char input1[10000];
	char input2[10000];
	char key1[1000];
	FILE *fp;

	int key;
	printf("[OTP] input: ");
	fgets (input, 1000000, stdin);

	one_pad(input);

	printf("[Caesars] input: ");
	fgets (input1, 1000000, stdin);
	int ln = strlen(input1)-1;
	if (input1[ln] == '\n')
    	input1[ln] == '\0';

	printf("[Caesars] key: ");
	scanf("%d",&key);
	getchar();

	Caesar(input1,key);

	printf("[Vigenere] input: ");
	fgets (input2, 1000000, stdin);
	if (input2[strlen(input2)-1] == '\n')
    	input2[strlen(input2)-1] == '\0';
	 printf("[Vigenere] key: ");
	fgets (key1, 1000000, stdin);
	if (key1[strlen(key1)-1] == '\n')
    	key1[strlen(key1)-1] == '\0';

	vigenere_cipher(input2,key1);


}