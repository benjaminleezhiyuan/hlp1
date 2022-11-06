/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 08
28/10/22
Brief
This file contains the declarations of the functions needed in qdriver.c
*/

#include <stdio.h> // for FILE*

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// initialize, wc, and print_freqs

/*initialize needs to be given input for  an array, size of the array, number of control characters and non latin characters respectively*/
void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt);

/*wc needs to be given the input for filestream, array, size of array, number of control characters and non latin characters respectively*/
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt);

/*print_freqs needs input for an array, size of array, number of control characters and non latin characters respectively*/
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt);