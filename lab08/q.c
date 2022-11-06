/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 08
28/10/22
Brief
This file contains the definitions for functions declared in q.h.
A text file is input into the program and the program will count the number of latin characters, control characters
and any remaining characters that do not fit into the first 2 categories.
It will output a file that shows the number of each latin character counted, sum of total latin characters,
total control characters and total of the non-latin and non control characters.
*/
#include <stdio.h>   // do not remove

// IMPORTANT NOTE: Other than functions fgetc, printf, or fprintf [which are declared in <stdio.h>],
// you must not use any other C standard library function in your submission.

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

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt){
int i =0;
while(i<size){ //sets every element of the array to be 0;
    latin_freq[i]=0;
    i++;
}
*ctrl_cnt=0;
*non_latin_cnt=0;
}
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
int chartemp;

while((chartemp=fgetc(ifs))!=EOF){
    if(chartemp >='a' && chartemp <= 'z'){//checks if character is a lower case alpha
        chartemp-='a';
        latin_freq[chartemp]++;
    }
    else if(chartemp >= 'A' && chartemp <= 'Z'){//checks if character is an upper case alpha
        chartemp-='A';
        latin_freq[chartemp]++;
    }
    //checks if characters is a control character.
    else if(chartemp=='\a' || chartemp== '\b' || chartemp== '\f' || chartemp== '\n' || chartemp== '\r' || chartemp== '\t' || chartemp== '\v'){
        (*ctrl_cnt)++;
    }

    else (*non_latin_cnt)++;//counts all remaining characters.
}


}
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt){
   int i=0;
   while(i<size){
    printf("%-10c",('a'+i));
    i++;
    if(i==size){
        printf("\n");
    }
   }

   i=0;
   while(i<size){
    printf("%-10d",latin_freq[i]);
    i++;
    if(i==size){
        printf("\n\n");
    }
   }

   i=0;
   int sum=0; 
   while(i<size){
    sum+=latin_freq[i];
    i++;
   }

   printf("Latin Letters     :%8d\n",sum);
   printf("Non-Latin Letters :%8d\n",*non_latin_cnt);
   printf("Control Letters   :%8d\n",*ctrl_cnt);

}