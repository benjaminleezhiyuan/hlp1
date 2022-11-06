/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 07
21/10/22
Brief
This file contains the declarations for the functions called by qdriver.c
*/
// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// read_total_count, read_3_numbers, swap, sort_3_numbers, and 
// maintain_3_largest

size_t read_total_count(void);
void swap(int* lhs, int* rhs);
void read_3_numbers(int* top1, int* top2, int* top3);
void sort_3_numbers(int* top1, int* top2, int* top3);
void maintain_3_largest(int number, int* top1, int* top2, int* top3);