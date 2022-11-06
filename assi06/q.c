/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 06
13/10/22
Brief
This file contains definitions for functions reverse_array,add_arrays,scalar_multiply,dot_product,
cross_product and length.
*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily meant for your clients.
// The documentation header here is primarily for use by you [and other on your team] solely t
// aid maintenance and debugging tasks ...

// @todo: If necessary, include q.h here ...
#include "q.h"
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...

/*reverse_array takes in an array and reverses the elements in the array*/
void reverse_array(int a[], int size){
    int start = 0;
    int end = (size - 1);
    int placeholder = 0;

    while (start < end) {
        placeholder = a[start];
        a[start] = a[end];
        a[end] = placeholder;
        start++;
        end--;
    }
}
/*adds the elements of 2 arrays*/
void add_arrays(int const a[], int const b[], int c[], int size) {
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }

}
/*multiplies the elements of an array by a scalar value*/
void scalar_multiply(int a[ ], int size, int scale_factor) {
    for (int i = 0; i < size; i++) {
        a[i] = a[i] * scale_factor;
    }
}
/*performs dot product function for 2 arrays*/
int dot_product(int const a[ ], int const b[ ], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total = total + (a[i] * b[i]);
        }
    return total;
}
/*performs cross product funtion of 2 arrays*/
void cross_product(int const a[ ], int const b[ ], int c[ ]) {
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}
double length(int const a[ ], int size) {
    double total = 0.f;
    for (int i = 0; i < size; i++) {
        total = total + ((double) a[i] * (double) a[i]);
        }
    double mag = sqrt(total);
    return mag;
}