/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 07
25/10/22
Brief
This file contains functions encrypt and decrypt that takes in input character by character
from a file and adds the corresponding value of the key character to encrypt and decrypt the text file.
*/
// TODO2: include other C standard library headers. for reasons 
// explained in previous assignments/labs, think carefully about 
// the need to add an include file before you do so ...
#include <stdio.h>
#include "q.h"
// TODO3: define functions encrypt and decrpyt ...
void encrypt(char* letter, char key)
{
    int cipher = (int)*letter + key;
    if (cipher > 127){
        cipher = cipher-128;
        *letter = (char)cipher;
    }
    else{
        *letter = (char)cipher;
    }
}
void decrypt(char* letter, char key)
{
    int decipher = (int)*letter - key;
    if (decipher <0 ){
        decipher = decipher + 128;
        *letter = (char)decipher;
    }
    else{
        *letter = (char)decipher;
    }
}