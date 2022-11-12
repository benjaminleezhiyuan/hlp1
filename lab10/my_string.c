/*
my_string.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 10
11/11/22
Brief
This file contains self defined string.h functions strlen, strcpy, strcat, strcmp and strstr
*/

// @todo: Add necessary C standard library headers here ...
#include "my_string.h"
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in my_string.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in my_string.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in my_string.h ...
size_t my_strlen(const char *str)
{
    size_t count;
    for (count = 0; str[count] != '\0'; count++) // counts number of characters in string not including the null character.
    {
    }
    return count;
}
char *my_strcpy(char *dest, const char *src)
{
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i]; // copies string to destination without null character
    }
    dest[i] = '\0'; // sets last character in destination to null character
    return dest;
}

char *my_strcat(char *dest, const char *src) // copies string to null character of destination (copies to the end)
{
    int i = 0, j = 0;
    for (; dest[i] != '\0'; i++, j++) // finds the null character of destination
    {
        dest[j] = dest[i];
    }

    for (i = 0; src[i] != '\0'; i++, j++) // copies src to destination starting with null character
    {
        dest[j] = src[i];
    }
    dest[j] = '\0'; // sets last character of dest to null character
    return dest;
}

int my_strcmp(const char *lhs, const char *rhs) // compares two strings, returns 3 values based on outcome.
{
    while (*lhs != '\0' || *rhs != '\0') // checks that both are the same length
    {
        if (*lhs == *rhs) // if characters are equal continue checking next set of characters
        {
            lhs++;
            rhs++;
        }
        else if ((*lhs == '\0' && *rhs != '\0') || (*lhs != '\0' && *rhs == '\0') || *lhs != *rhs) // if either first string ended before second
                                                                                                   // or second ends before first
                                                                                                   // or if current characters not equal
        {
            if (*lhs < *rhs) // if first character is smaller return -1
                return -1;
            else
                return 1; // else return 1
            break;
        }
    }
    return 0;
}
char *my_strstr(const char *str, const char *substr)//find substring inside string
{
    char *c = (char *)str;
    char *s1, *s2;

    while (*c)
    {
        s1 = c;
        s2 = (char *)substr;
        while (*s1 && *s2 && !(*s1 - *s2))
        {
            s1++;
            s2++;
        }
        if (!*s2)
        {
            return c;
        }
        c++;
    }
    return NULL;
}
