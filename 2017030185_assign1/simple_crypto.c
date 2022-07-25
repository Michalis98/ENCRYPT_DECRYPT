#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "simple_crypto.h"
#include <string.h>


void Caesar(char message1[],int key1){

	char message[strlen(message1)], ch;
	
	for (int i=0;i<=strlen(message1);i++){
		message[i]=message1[i];
	}

	
	int i, key,number,number2,number3;
	key=key1;
	key = key % 62;
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		number = key + ch - 48;
		number2 = key + ch ;
		number3 = ch-97;
		char ch1=ch;
		ch=ch+key;
		char a;
		char b;
		
		//printf("Number: %d", number);
		//printf("Encrypted message: %c", ch);
		
		if (ch1 >= '0' && ch1 <= '9'){
			
			int flag;
			a= ch-'9'+'A'-1;

			b=ch;
			//printf("%d : %d \n",a,b );


			if( (abs(ch) > '9' ) && (a <='Z'))
			{
				ch = ch-'9'+'A'-1;
				flag=1;
			}

			a=ch-'9'+'A';
			b=ch-'9'+'A'-'Z'+'a'-2;
			//printf("%d : %d \n",a,b );

			if((a > 'Z') && b<='a')
			{
				ch = ch-'9'+'A'-'Z'+'a'-2;
				flag=2;
			}

			a=ch-'9'+'A'-'Z'+'a';
			b=ch-'9'+'A'-'Z'+'a'-'z'+'0'-3;
			
			if( (b >= '0'))
			{
				ch = ch-'9'+'A'-'Z'+'a'-'z'+'0'-3;
				flag=3;
			}

			//printf("\nEncrypted message: %d flag :%d \n", ch,flag);

		}
		else if(ch1 >= 'a' && ch1 <= 'z'){
			int flag;
			a= ch-'z'+'0'-1;

			b=ch;
			//printf("%d : %d \n",a,b );


			if( (abs(ch) > 'z' ) && (a <='9'))
			{
				ch = ch-'z'+'0'-1;
				flag=1;
			}

			a=ch-'z'+'0';
			b=ch-'z'+'0'-'9'+'A'-2;
			//printf("%d : %d \n",a,b );

			if((a > '9') && b<='Z')
			{
				ch = ch-'z'+'0'-'9'+'A'-2;
				flag=2;
			}

			a=ch-'z'+'0'-'9'+'A';
			b=ch-'z'+'0'-'9'+'A'-'Z'+'a'-3;
			
			if( (b >= 'a'))
			{
				ch = ch-'z'+'0'-'9'+'A'-'Z'+'a'-3;
				flag=3;
			}


			//printf("\nEncrypted message: %d flag :%d \n", ch,flag);
		}
	    else if(ch1>= 'A' && ch1 <= 'Z'){
	    	int flag;
			a= ch-'Z'+'a'-1;

			b=ch;
			//printf("%d : %d \n",a,b );


			if( (abs(ch) > 'Z' ) && (a <='z'))
			{
				ch = ch-'Z'+'a'-1;
				flag=1;
			}

			a=ch-'Z'+'a';
			b=ch-'Z'+'a'-'z'+'0'-2;
			//printf("%d : %d \n",a,b );

			if((a > 'z') && b<='9')
			{
				ch = ch-'Z'+'a'-'z'+'0'-2;
				flag=2;
			}

			a=ch-'Z'+'a'-'z'+'0';
			b=ch-'Z'+'a'-'z'+'0'-'Z'+'a'-'z'+'A'-3;
			
			if( (b >= 'A'))
			{
				ch = ch-'Z'+'a'-'z'+'0'-'Z'+'a'-'z'+'A'-3;
				flag=3;
			}

		}
		message[i] = ch;
	}
		
		
	message[++i]='\0'; 
	printf("[Caesars] encrypted: %s\n", message);

	char message3[strlen(message)], ch2;
	
	for(i = 0; i<strlen(message); i++){
		ch = message[i];
		number = key + ch - 48;
		number2 = key + ch ;
		number3 = ch-97;
		char ch1=ch;
		ch=ch-key;
		char a;
		char b;

		message3[i] = ch;
	}
	message3[i]='\0'; 
	printf("[Caesars] decrypted: %s", message3);
	
	return 0;

}


void one_pad(char input1[]){

char input[strlen(input1)];

for (int i=0;i<=strlen(input1);i++){
	input[i]=input1[i];
}

char randomdata[strlen(input)];
char encrypted[strlen(input)];
char decrypted[strlen(input)];
char myRandomData[strlen(input)];
//making the random key
int randomData = open("/dev/urandom", O_RDONLY);


if (randomData < 0)
{
    return;
}
else
{
    
    int result = read(randomData, myRandomData, sizeof myRandomData);
    if (result < 0)
    {
        return;
    }
}

printf("[OTP] encrypted: ");
for (int i=0;i<strlen(input);i++){

	encrypted[i]= myRandomData[i]^input[i];
	
	printf("%02x", encrypted[i]);
}


printf("\n[OTP] decrypted: ");
for (int i=0;i<strlen(input);i++){

	decrypted[i]= encrypted[i]^myRandomData[i];
	
	printf("%c", decrypted[i]);
}
//printf("\n[OTP] decrypted: %s" , decrypted);



}


void vigenere_cipher(char messa[],char key1[]){

	char msg[strlen(messa)];
	char key[strlen(key1)];

	for (int i=0;i<=strlen(messa);i++){
		msg[i]=messa[i];
	}

	for (int i=0;i<=strlen(key1);i++){
		key[i]=key1[i];
	}

	
    //char key[] = key;
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 
    encryptedMsg[i-1] = '\0';
 
    //decryption
    for(i = 0; i < msgLen; ++i)
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedMsg[i-1] = '\0';
 

    printf("[Vigenere] encrypted: %s", encryptedMsg);
    printf("\n[Vigenere] decrypted: %s", decryptedMsg);
 
  return 0;

}
