// TODO: File documentation block required

// TODO: Include all necessary C standard library headers 
#include <stdio.h>
#include <stdlib.h>
#include "q.h"
// TODO: Definitions of functions declared in q.h go here ...
struct Tsunami tsu;
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt)
{   
    FILE *open = (file_name,"r")
    if(NULL == open)
    {
        exit(EXIT_FAILURE);
    }

    int count=0;
    while(EOF!=fscanf(open,"%d %d %d %d %f %80[^\n]",&tsu.day,&tsu.month,&tsu.year,&tsu.fatalities,&tsu.maxwave,tsu.location))
    {
        
    }





    fclose(open);
}