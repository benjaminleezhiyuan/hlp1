/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 05
30/09/22
Brief
This file contains the definition of function cost and rev.
cost takes in age and number of accidents of a driver and outputs the total cost 
of insurance.
rev takes in an integer value and outputs the same value in reverse.

*/

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include "q.h"

void cost(void)
{
    int age,accidents,cost;
    scanf("%d,%d",&age,&accidents);
    cost = 500;

    if (accidents<1)
    {
        cost = 500;
    }
    else if(accidents<3)
    {
        cost +=100;
    }
    else if(accidents <5)
    {
        cost+=225;
    }
    
    if(age<16)
    {
        printf("%s%d%s%d%s","age = ",age,", number of accidents = ",accidents,", no insurance coverage!");
    }
    else if(age<25 && accidents<5)
    {
        cost +=50;
        printf("%s%d%s%d%s%d", "age = ",age,", number of accidents = ",accidents,", insurance cost = ",cost);

    }
    else if(age<25 && accidents>4)
    {
        printf("%s%d%s%d%s","age = ",age,", number of accidents = ",accidents,", no insurance coverage!");
    }
    else if(age>24 && accidents<5)
    {
        printf("%s%d%s%d%s%d", "age = ",age,", number of accidents = ",accidents,", insurance cost = ",cost);
    }
    else if(age>24 && accidents>4)
    {
        printf("%s%d%s%d%s","age = ",age,", number of accidents = ",accidents,", no insurance coverage!");
    }
    
    printf("\n");


}

void rev(void)
{
    int value,rev=0,negative;
    scanf("%d",&value);
    if (value<0){
        negative = value;
        value = -value;
    }

    while(value!=0){
        rev = rev*10 + value%10;
        value = value/10;
    }

    if(negative<0){
    printf("-%d\n",rev);
    }
    else{
    printf("%d\n",rev);
}
}
