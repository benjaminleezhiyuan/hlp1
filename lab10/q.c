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

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count)
{
    size_t filesize = 0;
    for(size_t i=0; i<count; i++)
    {
        filesize += STRLEN(folders[i])+STRLEN(separator);
    }

    char *endpath = debug_malloc(filesize+STRLEN(parent)+1);
    STRCPY(endpath,separator);
    STRCAT(endpath,parent);
    STRCAT(endpath,separator);
    for(size_t i=1; i<count; i++)
    {
        STRCAT(endpath,folders[i]);
        STRCAT(endpath,separator);
    }
    
}
void compare_string(const char* lhs,const char* rhs)
{

}
void describe_string(const char* text)
{

}
void find_string(const char* string, const char* substring)
{

}