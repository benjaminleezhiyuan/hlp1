/*!
q.c 
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22 
Section A 
Assignment 03
13/09/22 
@brief
This file contains the definition of function temp_converter. It takes in the value of
temperature in fahrenheit and converts it into celcius and kelvin and prints it out 
accordingly.
*//*______________________________________________________________________*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function temp_converter to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include "q.h"
// @todo: Provide the definition of function temp_converter that
// matches the declaration in q.h ...

double c, k;

void temp_converter(int f){

    c = ((f-32.00)*5)/9;
    k = c + 273.15;

    printf("%-15s%-15s%-15s\n","Fahrenheit","Celsius","Kelvin");
    printf("---------------------------------------------\n");
    printf("%-15d%-15.2f%-15.2f\n",f,c,k);

    }
