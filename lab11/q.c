/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 11
18/11/22
Brief
This file contains functions that prints out the contents of array and formats it
according to the values given.
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
    char *hex = (char *)ptr;          // hex becomes char ptr
    for (size_t i = 0; i < size; i++) // goes through entire array
    {
        printf("%x ", *(hex + i)); // prints byte with space in between

        if ((i + 1) % 4 == 0) // prints 3 spaces every 4 bytes
        {
            printf("  ");
        }

        if ((i + 1) % span == 0) // prints | when reaches span (max byte per line)
        {
            printf("|");

            for (size_t j = i - span + 1; j <= i; j++) // goes through element inside element 
            {
                if (j % 4 == 0)
                {
                    printf("   ");
                }
                printf("%c%s", *(hex + j), (j + 1) % 4 == 0 ? "" : " ");
            }
            printf("\n");
        }
    }
}
