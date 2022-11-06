/*
qdriver.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 07
25/10/22
Brief
This file contains all the opening, closing, reading to and writing to of files needed.
This program lets you input any .txt file and will encrypt and decrypt the whole file
according to what keyword is used.
*/
#include <stdio.h>	// file and console I/O

#include "q.h"	// include declarations and the decryption keyword

int main(void)
{	
	int index=0;
	char key[index];
	char keychar, chartemp;
	int j = 0,character, keytemp;
	
	#ifdef ENCRYPT
	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt

	/*open files needed for encrypt*/
	FILE *keytext = fopen("key.txt","r");
	FILE *plaintext = fopen("plain.txt", "r");
	FILE *ciphertext = fopen("cipher.txt", "w");

	if(keytext == NULL){
		printf("Unable to open file key.txt\n");
		return 1;
	}
	
	while((keytemp=fgetc(keytext))!=EOF){
		key[index]=(char)keytemp;
		index++;
		
	}
	
	if (plaintext == NULL) {

		printf("Unable to open file plain.txt\n");
		return 1;
	}

	if (ciphertext == NULL) {

		printf("Unable to open file cipher.txt\n");
		return 1;
	}
	
	while ((character = fgetc(plaintext)) != EOF) {

		chartemp = (char) character;
		
		if (j >= (index - 1)) {

			j = 0;
		}

		keychar = key[j];

		encrypt(&chartemp, keychar);

		fputc(chartemp, ciphertext);

		j++;
	}
	fclose(plaintext);
	fclose(ciphertext);
	fclose(keytext);
	
	#else

	// TODO4: read characters from input file cipher.txt and write the
	// corresponding decrypted characters to output file out-plain.txt
	// using the keyword in file key.txt
	int wordcount = 0;
	
	FILE *keytext = fopen("key.txt","r");
	FILE *ciphertext = fopen("cipher.txt", "r");
	FILE *plaintext = fopen("out-plain.txt", "w");
	FILE *onlyspaces = fopen("onlyspaces.txt","w");
	

	if(keytext == NULL){
		printf("Unable to open file key.txt\n");
		return 1;
	}
	
	if (ciphertext == NULL) {
		printf("Unable to open file cipher.txt\n");
		return 1;
	}
	if (plaintext == NULL) {

		printf("Unable to open fileplain.txt\n");
		return 1;
	}

	if(onlyspaces == NULL){
		printf("Unable to open file onlyspaces.txt\n");
		return 1;
	}

	int keysize= 0;
	while((keytemp=fgetc(keytext))!=EOF){
		key[index]=(char)keytemp;
		index++;
		keysize++;
	}

	while ((character = fgetc(ciphertext)) != EOF) {
		chartemp = (char) character;
		
		if (j >= (index - 1)) {

			j = 0;
		}

		keychar = key[j];
		decrypt(&chartemp, keychar);
		fputc(chartemp, plaintext);
		j++;
	}
	fclose(plaintext);
	fclose(ciphertext);

	char actualtemp;
	FILE *plaintextopen = fopen("out-plain.txt","r");
	while((character=fgetc(plaintextopen))!=EOF){
		actualtemp = (char) character;
		if(actualtemp == '\r' || actualtemp == '\t' || actualtemp == '\n'){
			actualtemp=' ';
			fputc(actualtemp,onlyspaces);
		}
		else fputc(actualtemp,onlyspaces);
	}
	fclose(plaintextopen);
	fclose(onlyspaces);

	FILE *input = fopen("onlyspaces.txt","r");
	char prevchar='x';
	while((character=fgetc(input))!=EOF){
		
		if (prevchar!=' '&& character==' ') {
			wordcount++;
		}
		prevchar = (char)character;
	}
	// TODO5: write count of words into stderr
	fprintf(stderr,"Words: %d\n",wordcount);
	fclose(input);
	#endif

	return 0;
}
