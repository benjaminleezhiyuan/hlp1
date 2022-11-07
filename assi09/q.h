#ifndef Q_H
#define Q_H

// TODO: File documentation block required

// TODO: Include only those C standard library headers that declare/define names used in functions declared below

// TODO: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?

// TODO: Now, declare the necessary function.

// TODO: Repeat function documentation block plus function declaration for remaining functions
typedef int numbers;
typedef double height;
typedef unsigned char geo[81];
struct Tsunami[100]
{
    numbers day;
    numbers month;
    numbers year;
    numbers fatalities;
    height maxwave;
    geo location; 
};


/*
typedef struct
{
    int day;
    int month;
    int year;
    int fatalities;
    double height;
    unsigned char location;
}Tsunami;
*/

int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);
void print_info(struct Tsunami const *arr, int size, FILE *out_stm);
double get_max_height(struct Tsunami const *arr, int size);
double get_average_height(struct Tsunami const *arr, int size);
void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm);

#endif

