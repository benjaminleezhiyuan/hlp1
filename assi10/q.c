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
#include <math.h>
#undef max
#undef min
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

    rewind(read);
    double *heap;
    heap = malloc(sizeof(double) * count);
    double num = 0.0;
    int i;
    for (i = 0; fscanf(read, "%lf", &num) != EOF; i++)
    {
        *(heap + i) = num;
    }
    fclose(read);
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

/*void swap(double *lhs, double *rhs)
{
    double temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}*/

void selection_sort(double *base, int size)
{
    double temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(base + i) > *(base + j))
            {
                temp = *(base + i);
                *(base + i) = *(base + j);
                *(base + j) = temp;
            }
        }
    }
}

double median(double *base, int size)
{
    double median;
    selection_sort(base, size);

    if (size % 2 == 0)
        median = (*(base + (size / 2)) + *(base + (size / 2) - 1)) / 2.0;
    else
        median = *(base + (size / 2));

    return median;
}

void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades)
{
    double a = 0, b = 0, c = 0, d = 0, f = 0, count = 0;
    for (; begin < end; begin++)
    {
        if (*begin >= 90.0)
        {
            a++;
            count++;
        }
        else if (*begin < 90.0 && *begin >= 80.0)
        {
            b++;
            count++;
        }
        else if (*begin < 80.0 && *begin >= 70.0)
        {
            c++;
            count++;
        }
        else if (*begin < 70.0 && *begin >= 60.0)
        {
            d++;
            count++;
        }
        else
        {
            f++;
            count++;
        }
    }
    *ltr_grades = a/count*100;
    *(ltr_grades + 1) = b/count*100;
    *(ltr_grades + 2) = c/count*100;
    *(ltr_grades + 3) = d/count*100;
    *(ltr_grades + 4) = f/count*100;
    *(ltr_grades + 5) = count;
}