/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 05
30/09/22
Brief -
This file contains delcarations for functions trapezoid_pi,montecarlo_pi and leibniz_pi.
*/
// @todo: Provide function-level documentation header as explained in Assignment 2 specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve problems that require pi's value.
// In a commercial environment, the source file q.c containing definitions of
// functions that compute pi is your intellectual property and should therefore
// be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the three functions related to
// computing pi's value only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...
double trapezoid_pi(int num_of_rects);
double montecarlo_pi(unsigned int seed, int num_of_trails);
double leibniz_pi(int num_elements);