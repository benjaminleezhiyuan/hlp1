/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 11
18/11/22
Brief

*/
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include "q.h"

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

void print_data(
    const void *ptr, // Address of the first byte.
    size_t size,     // Total count of bytes.
    size_t span      // Count of bytes printed per line.
)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%x ", *((char *)(ptr) + i));

        if ((i + 1) % 4 == 0)
        {
            printf("  ");
        }

        if ((i + 1) % span == 0)
        {
            printf("|");

            for (size_t j = i - span + 1; j <= i; j++)
            {
                if (j % 4 == 0)
                {
                    printf("   ");
                }
                printf("%c%s", *((char *)(ptr) + j), (j + 1) % 4 == 0 ? "" : " ");
            }
            printf("\n");
        }
    }
}
