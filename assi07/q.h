/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 07
25/10/22
Brief
This file contains declarations for the funtions needed for
qdriver.c to function*/

#ifndef Q_H
#define Q_H

// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt

// TODO3: declaration for function encrypt
void encrypt(char* letter, char key);

// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt

// TODO5: declaration for function decrypt
void decrypt(char* letter, char key);

#endif // Q_H
