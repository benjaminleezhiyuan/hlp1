/*
q.h
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 11
18/11/22
Brief
Contains declarations for function print_data and struct Datum
*/

// @todo: Copy type aliases and macros from the current specs
struct Datum
{
    char upper;
    char lower;
    unsigned short int value;
};
typedef struct Datum DATUM;
typedef DATUM DATA[2];
// @todo: Provide function-level documentation header for each function
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the function print_data
void print_data(
    const void *ptr, // Address of the first byte.
    size_t size,     // Total count of bytes.
    size_t span      // Count of bytes printed per line.
);