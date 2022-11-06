/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22 
Section A 
Assignment 04
27/09/22
Brief
This file contains the definition of function decimal_to_roman.
The function takes in an integer value and converts and prints out
the corresponding value in roman numerals.
*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function decimal_to_roman to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include "q.h"
// @todo: Provide the definition of function decimal_to_roman that
// matches the declaration in q.h ...
void decimal_to_roman(int value)
{
    while(value != 0)//Converts decimal to Roman Numerals
    {
        if (value >= 1000) //prints M
        {
           printf("M");
           value -= 1000;
        }

        else if (value >= 900)//prints CM
        {
           printf("CM");
           value -= 900;
        }        

        else if (value >= 500)//prints D
        {           
           printf("D");
           value -= 500;
        }

        else if (value >= 400)//prints CD
        {
           printf("CD");
           value -= 400;
        }

        else if (value >= 100)//prints C
        {
           printf("C");
           value -= 100;                       
        }

        else if (value >= 90)//prints XC
        {
           printf("XC");
           value -= 90;                                              
        }

        else if (value >= 50)//prints L
        {
           printf("L");
           value -= 50;                                                                     
        }

        else if (value >= 40)//prints XL
        {
           printf("XL");           
           value -= 40;
        }

        else if (value >= 10)//prints X
        {
           printf("X");
           value -= 10;           
        }

        else if (value >= 9)//prints IX
        {
           printf("IX");
           value -= 9;                         
        }

        else if (value >= 5)//prints V
        {
           printf("V");
           value -= 5;                                     
        }

        else if (value >= 4)//prints IV
        {
           printf("IV");
           value -= 4;                                                            
        }

        else if (value >= 1)//prints I
        {
           printf("I");
           value -= 1;                                                                                   
        }

    }
    printf("\n"); //goes to next line after converting decimal to roman
}