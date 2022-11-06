/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 08
28/10/22
Brief

*/
// NOTE 2: Even if you don't need the NULL, don't remove this macro ...
#define NULL ((void*)0) 

// NOTE 3: When uploading this file for grading, make sure to remove all
// standard library  from this file.
// The auto-grader will not accept your submission if the file contains
//  directives.

// NOTE 4: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the  or  symbols from your code. 
// It is important that even your comments should not  these symbols.

// TODO: Definitions of functions declared in q.h go here ...
char const* find(char const *begin, char const *end, char val)
{
    for (;begin<end;begin++)
    {
        if(*begin==val)
        {
            return begin;
        }
    }
    return NULL;
}
char const *find_any(char const *begin, char const *end, char const *vals, int len)
{
    for (;begin < end; begin++)
    {
        for (char const *pog = vals; pog < vals + len; pog++)
        {
            if (*begin == *pog)
                return begin;
        }
    }
    return NULL;
}
int count(char const *begin, char const *end, char val)
{   int i=0;
    for (;begin<end;begin++)
    {
       if(*begin==val)
       {
           i++;
       }
    }
    return i;
}
int count_any(char const *begin, char const *end, char const *vals, int len)
{   int i=0;
    for (;begin<end;begin++)
    {
        for(char const *pog=vals; pog < vals +len; pog++)
        {
            if(*begin==*pog)
            {
                i++;
            }
        }
    }
    return i;
}
int compare(char const *begin1, char const *begin2, int len){
    int flag;
    for(int i=0;i<len;i++,begin1++,begin2++){
        if(*begin1==*begin2)
        {
            flag=0;
        }
        if(*begin1<*begin2)
        {
            flag=-1;
            break;
        }
        if(*begin1>*begin2)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
void swap(char *left,char *right){
    char temp=*left;
    *left=*right;
    *right = temp;
}
void exchange(char *begin1, char *begin2, int len)
{
    for(int i=0;i<len;i++,begin1++,begin2++)
    {
        swap(begin1,begin2);
    }
}

void copy(char *dst, char *src, int len)
{
    if(src>dst)//src is on the right of dst
    {
        for(int i=0;i<len;i++,dst++,src++)
        {
            *dst=*src; //starts copying from left to right
        }
    }
    if(src<dst)//src is on the left of dst
    {   
        for(int i=1;i<=len;i++)
        {
            *(dst+len-i)=*(src+len-i); //starts copying from right to left

        }
    }
}

















