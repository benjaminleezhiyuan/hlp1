/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 09
07/11/22
Brief
These functions will read an input of tsunami data and output the information for the date,
fatalities, max height and location of the tsunami.
It will also calculate and output the tsunami with the greatest max height, average of 
all the max heights and which tsunamis are greater than the average.
*/

// TODO: Include all necessary C standard library headers 
#include <stdio.h>
#include <stdlib.h>
#include "q.h"
// TODO: Definitions of functions declared in q.h go here ...
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt)
{   
    FILE *open = fopen(file_name ,"r");
    if(NULL == open)
    {
        exit(EXIT_FAILURE);
    }

    int count=0;
    while(EOF!=fscanf(open,"%d %d %d %d %lf %[^\n]",&(arr+count)->month,&(arr+count)->day,
    &(arr+count)->year,&(arr+count)->fatalities,&(arr+count)->maxwave,(arr+count)->location) && count<max_cnt)
    {
        count++;
    }
    fclose(open);
    return count;
}

void print_info(struct Tsunami const *arr, int size, FILE *out_stm)
{
    for(int i=0; i<size; i++)
    {
        fprintf(out_stm,"%02d %02d %4d %6d %5.2f %s\n",(arr+i)->month,(arr+i)->day,(arr+i)->year,
        (arr+i)->fatalities,(arr+i)->maxwave,(arr+i)->location);
    }
}

double get_max_height(struct Tsunami const *arr, int size)
{
    double maxheight = arr->maxwave;

    for(int i=0 ; i<size ; i++)
    {
        if(maxheight>(arr+i)->maxwave)
        {
            maxheight = maxheight;
        }
        else
        {
            maxheight = (arr+i)->maxwave;
        }
    }
    return maxheight;
}

double get_average_height(struct Tsunami const *arr, int size)
{
    double average = 0.f;

    for(int i=0; i<size ; i++)
    {
        average += (arr+i)->maxwave;
    }
    average /= size;
    return average;
}

void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm)
{
    for(int i=0; i<size ; i++)
    {
        if((arr+i)->maxwave>height)
        {
            fprintf(out_stm,"%5.2f %s\n",(arr+i)->maxwave,(arr+i)->location);
        }
    }
}