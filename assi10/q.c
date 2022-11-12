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
#include <stdio.h>
#include <stdlib.h>
// TODO: Definitions of functions declared in q.h go here ...
double *read_data(char const *file_name, int *ptr_cnt)
{
    FILE *read = fopen(file_name, "r");
    if (read == NULL)
    {
        return NULL;
    }
    int count = 0;
    char ch;
    while ((ch = fgetc(read)) != EOF)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
        {
            count++;
        }
    }
    *ptr_cnt = count;
    double *heap = malloc(count * sizeof(double));
    double num = 0;
    while (fscanf(read, "%lf", &num) != EOF)
    {
        *heap = num;
        heap++;
    }
    return heap;
}