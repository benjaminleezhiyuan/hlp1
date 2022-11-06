/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 07
21/10/22
Brief
This file contains the definitions for the functions declared in the q.h header.
It allows qdriver to take in a number of values and output the 3 largest values in descending
order.
*/

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <stdlib.h>
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...

size_t read_total_count(void){//lets the program know how many integers you are inputting
    size_t count;
    printf("Please enter the number of integers: ");
    scanf("%zu",&count);
    if(count<3){//if number of integers are less than 3 prorgam exits.
        printf("There is no third largest number.\n");
        exit(EXIT_FAILURE);
    }    
    return count;
}

void read_3_numbers(int* top1, int* top2, int* top3){ //reads 3 numbers and stores them inside pointer address.
    scanf("%d %d %d",top1,top2,top3);
}

void swap(int* lhs, int* rhs){//swaps 2 pointer values.
    int temp = *lhs;
    *lhs=*rhs;
    *rhs=temp;
}

void sort_3_numbers(int* top1, int* top2, int* top3){//sorts the numbers in order of largest to smallest.

    if(*top1<*top3 && *top1>*top2){    
            swap(top1,top2);
            swap(top1,top3);   
    }    
    else if(*top1<*top2 && *top2<*top3 && *top3>*top1){
            swap(top1,top3);  
    }
    else if(*top3<*top2 && *top3>*top1){
            swap(top3,top2);
            swap(top1,top3);
    }
    else if(*top1>*top2 && *top2<*top3){
        swap(top2,top3);
    }
}
    

void maintain_3_largest(int number, int* top1, int* top2, int* top3){ //introduces a new number and rearranges the 3 largest numbers accordingly.
   if(number>*top1){
        swap(top2,top3);
        swap(top2,top1);
        *top1=number;
    }
    else if(number>*top2){
        swap(top2,top3);
        *top2=number;
    }
    else if(number>*top3){
        *top3=number;
    }
}