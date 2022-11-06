/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 06
13/10/22
Brief
This file contains declarations for the funtions needed in qdriver.c
*/

// @todo: Provide function-level documentation header as explained in the specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve certain problems related to linear algebra.
// In a commercial environment, the source file q.c containing definitions of
// functions that solve linear algebra problems is your intellectual property and should
// therefore be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the functions related to solving
// linear algebra problems only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...
void reverse_array(int a[], int size);
void add_arrays(int const a[], int const b[], int c[], int size);
void scalar_multiply(int a[ ], int size, int scale_factor);
int dot_product(int const a[ ], int const b[ ], int size);
void cross_product(int const a[ ], int const b[ ], int c[ ]);
double length(int const a[ ], int size);