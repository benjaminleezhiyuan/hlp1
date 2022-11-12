/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 10
11/11/22
Brief
This file contains functions that take folders and merges them together to create a path
directory.
It also allows you to compare different strings of filepaths and find substring in a string of paths.
*/
// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...
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

const char *build_path(const char *parent, const char *separator, const char *const folders[], size_t count)
{
    size_t filesize = STRLEN(parent) + 1; // gets the size of the parent plus null character
    for (size_t i = 0; i < count; i++)
    {
        filesize += STRLEN(folders[i]) + STRLEN(separator); // adds size of each folder and separator into total filesize
    }
    char *path = debug_malloc(filesize); // allocates proper size for path
    STRCPY(path, parent);                // copy first char to path
    for (size_t i = 0; i < count; i++)
    {
        STRCAT(path, folders[i]); // adds folder directories to path
        STRCAT(path, separator);  // adds seperator between each folder
    }
    return path;
}
void compare_string(const char *lhs, const char *rhs)
{
    int ch;
    ch = STRCMP(lhs, rhs); // compares two strings, returns 0 if equal, <0 if first string goes first and >0 if second string goes first.
    if (ch == 0)
    {
        fprintf(stdout, "Both strings are equal.\n");
    }
    else if (ch > 0)
    {
        fprintf(stdout, "Right string goes first.\n");
    }
    else if (ch < 0)
    {
        fprintf(stdout, "Left string goes first.\n");
    }
}

void describe_string(const char *text) // prints out the path.
{
    fprintf(stdout, "The length of the path \"%s\" is %ld.\n", text, STRLEN(text));
}

void find_string(const char *string, const char *substring) // finds substring within a string
{
    long int position = STRSTR(string, substring) - string; // returns pointer to the first occurrence of substring in string
    printf("Searching for a string:\n");
    printf("\t%-10s%s\n", "Text:", string);
    printf("\t%-10s%s\n", "Sub-text:", substring);
    if (!STRSTR(string, substring))
    {
        printf("\tResult:   not found\n");
    }
    else
    {
        printf("\tResult:   found %ld characters at a position %ld.\n", STRLEN(substring), position);
    }
}