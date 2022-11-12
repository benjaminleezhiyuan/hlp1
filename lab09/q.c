/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 09
04/11/22
Brief
Program reads text files and allows for the conversion of lower case to upper case
Can return number of words starting with any given character.
Check for spelling and return if the word is spelt correctly, incorrectly or is not found.
Returns the amount of words that have 1,2,3,4 and 5 characters in them.

*/

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
char* str_to_upper(char* string)
{
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]>='a' && string[i]<='z')
        {
            string[i] = (char)toupper(string[i]);
        }
    }
    return string;
}

WordCount words_starting_with(const char* dictionary, char letter)
{
    WordCount count = 0;
    char character[LONGEST_WORD];
    FILE *open=fopen(dictionary, "r");
    if(open == NULL) return FILE_ERR_OPEN;

    while(fgets(character, LONGEST_WORD,open)!=NULL)
    {
        str_to_upper(character);
        str_to_upper(&letter);
        if(*character == letter)
        {
            count++;
        }
    }
    fclose(open);
    return count;
}
ErrorCode spell_check(const char* dictionary, const char* word)
{
    FILE *open = fopen(dictionary, "r");
    char word1[LONGEST_WORD];
    strcpy(word1,word); 
    str_to_upper(word1);
    char wordcheck[LONGEST_WORD];
    
    if (open == NULL)
    {
        return FILE_ERR_OPEN;
    }
        while(fgets(wordcheck,LONGEST_WORD,open) != NULL)
        {
          str_to_upper(wordcheck);
          for (int count = 0; count < LONGEST_WORD;++ count)
                {
                    if (wordcheck[count] == '\n')
                    {
                        wordcheck[count] = '\0';
                    }
                }
                if (strcmp(word1,wordcheck) == 0)
                {
                    return WORD_OK;
                }
        }    
    return WORD_BAD ;
    fclose(open);
    }

ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count)
{
    int i;
    char character[LONGEST_WORD];
    FILE *open=fopen(dictionary, "r");
    if(open == NULL) return FILE_ERR_OPEN;

    while(fgets(character, LONGEST_WORD,open)!=NULL)
    {
        for(i=0;i<=count;i++)
        {
            if((int)strlen(character)==i+1)
            {
                lengths[i]++;
            }
        }
    }
    return 0;
}
ErrorCode info(const char* dictionary, DictionaryInfo* info)
{
    FILE *open=fopen(dictionary, "r");
    if(open == NULL) return FILE_ERR_OPEN;

    char word[LONGEST_WORD];
    int wordcount=1,shortest=0,longest=0;
    fgets(word,LONGEST_WORD,open);
    int out=(int)strlen(word);
    out--;
    shortest = out;
    longest = out;
    while(fgets(word,LONGEST_WORD,open)!=NULL)
    {
        int in=(int)strlen(word);
        in--;
        if(in>longest)
        {
            longest=in;
        }
        if(in<shortest)
        {
            shortest=in;
        }
        wordcount++;
    }
    info->count=wordcount;
    info->shortest=(WordLength)shortest;
    info->longest=(WordLength)longest;
    return 0;
}
