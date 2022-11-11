// @todo: Add a file documentation header as explained in the specs ...

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
    for (count = 0; str[count] != '\0'; count++)
    {
    }
    return count;
}
char *my_strcpy(char *dest, const char *src)
{
    size_t i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    int i = 0, j = 0;
    for (; dest[i] != '\0'; i++, j++)
    {
        dest[j] = dest[i];
    }

    for (i = 0; src[i] != '\0'; i++, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return dest;
}

int my_strcmp(const char *lhs, const char *rhs)
{
    while (*lhs != '\0' || *rhs != '\0')
    {
        if (*lhs == *rhs)
        {
            lhs++;
            rhs++;
        }
        else if ((*lhs == '\0' && *rhs != '\0') || (*lhs != '\0' && *rhs == '\0') || *lhs != *rhs)
        {
            if (*lhs < *rhs)
                return -1;
            else
                return 1;
            break;
        }
    }
    return 0;
}
char *my_strstr(const char *str, const char *substr)
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
