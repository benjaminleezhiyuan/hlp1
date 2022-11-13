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
#include <math.h>
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

double max(double const *begin, double const *end)
{
    double max = 0;
    for (; begin != end; begin++)
    {
        max = *begin > max ? *begin : max;
    }
    return max;
}

double min(double const *begin, double const *end)
{
    double min = 100.00;
    for (; begin < end; begin++)
    {
        min = *begin < min ? *begin : min;
    }
    return min;
}

double average(double const *begin, double const *end)
{
    int count = 0;
    double average = 0.00;
    for (; begin < end; begin++, count++)
    {
        average += *begin;
    }
    average /= count;
    return average;
}

double variance(double const *begin, double const *end)
{
    int count = 0;
    double mean = average(begin, end);
    double sum = 0.0, variance = 0.0;
    for (; begin < end; begin++, count++)
    {
        sum += (*begin - mean) * (*begin - mean);
    }
    variance = sum / (count - 1);
    return variance;
}

double std_dev(double const *begin, double const *end)
{
    double var = variance(begin, end);
    double dev = sqrt(var);
    return dev;
}

double median(double *base, int size)
{
    
}