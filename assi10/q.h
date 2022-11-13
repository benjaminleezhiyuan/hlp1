/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 10
13/11/22
Brief
*/

#ifndef Q_H
#define Q_H


// TODO: declare anonymous enumeration type as described in the specs
enum
{
    A_GRADE = 0,
    B_GRADE = 1,
    C_GRADE = 2,
    D_GRADE = 3,
    F_GRADE = 4,
    TOT_GRADE = 5
};

// TODO: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?

// TODO: Now, declare the necessary function.
double *read_data(char const *file_name, int *ptr_cnt);
double max(double const *begin, double const *end);
double min(double const *begin, double const *end);
double average(double const *begin, double const *end);
double variance(double const *begin, double const *end);
double std_dev(double const *begin, double const *end);
double median(double *base, int size);
void swap(double* lhs, double* rhs);
void selection_sort(double *base, int size);
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);

// TODO: Repeat function documentation block plus function declaration for remaining functions

#endif // #ifndef Q_H
