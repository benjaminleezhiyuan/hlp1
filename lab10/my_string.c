// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...

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
size_t my_strlen(const char* str)
{
    for(size_t count=0; str[count]!= '\0';count++)
    {}
    return count;
}
char* my_strcpy(char* dest, const char* src)
{
    size_t count = my_strlen(src);
    for(i=0;i<count+1;src++,dst++)
    {
        *dest=*src;
    }
    return dest;
}
char* my_strcat(char* dest, const char* src);
int my_strcmp(const char* lhs, const char* rhs);
char* my_strstr(const char* str, const char* substr);
