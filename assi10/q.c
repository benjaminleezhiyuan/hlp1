/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 10
13/11/22
Brief
*/

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]

// TODO: Include all necessary C standard library headers
#include <stdio.h>;
// TODO: Definitions of functions declared in q.h go here ...
double *read_data(char const *file_name, int *ptr_cnt)
{
    FILE *read = fopen(file_name, "r");
    if (read == NULL)
    {
        return NULL;
    }
    int count = 1;
    char temp;
    while (temp = fgetc(read) != EOF)
    {
        if (temp = ' ')
        {
            count++;
        }
    }
    double *heap = malloc(count * sizeof(double));
}