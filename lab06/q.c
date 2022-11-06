/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Lab 06
11/10/22
Brief
This file contains the definitions for the functions declared in the q.h header.
*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily meant for your clients.
// The documentation header here is primarily for use by you [and other on your team] solely t
// aid maintenance and debugging tasks ...

// @todo: If necessary, include q.h here ...
#include "q.h"
// @todo: Add necessary C standard library headers here ...
#include "stdio.h"
#include "math.h"

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...

/*read_data takes in a text file containing varying amounts of grades 
and stores them into an array named grades[].*/
int read_data(double grades[],int size){
    int i = 0; // i is the value of the index stored into grades[]
    double num=0.0; // num is the numerical value of the grade that is stored into grades[i]
    /*This while loop reads every grade from the beginning of the file until the end when 
    there are no more values.*/
    while ( (scanf("%lf", &num) != EOF) && i < size ){
        grades[i++] = num; //stores the grade into array grades[]
    }
    return i; 
    
}
/*max_index will go through all the grades stored in the array and return the index of 
the largest grade. */
int max_index(double const arr[], int size){
    double max = arr[0];
    int max_i = 0;
    for(int i=1; i<size; i++){
        max = arr[i]>max ? arr[i]: max;
        if (max==arr[i]){
            max_i=i;
        }
    }
    return max_i;
}
/*min_index will go through all the grades stored in the array and return the index of
the smallest grade.*/
int min_index(double const arr[], int size){
    double min = arr[0];
    int min_i = 0;
    for(int i = 1; i<size; i++){
        min = arr[i]<min ? arr[i] : min;
        if(min==arr[i]){
            min_i=i;
        }
    }
    return min_i;
}
/*mean sums up all the grades stored in the arr[] array and divides it by the total amount of grades
giving us the mean*/
double mean(double const arr[], int size){
    double mean = arr[0];
    for(int i = 1; i<size;i++){
        mean += arr[i];//sum of all the grades stored in the array.
    }
    mean /=size;//mean of all the grades stored in the array.
    return mean;
}
double variance(double const arr[], int size){
    double mean = arr[0];
    if(size>1){
    for(int i =1; i<size;i++){
        mean += arr[i];
    }
    mean/=size;
    double sum = 0.0;
    for(int i = 0; i<size; i++){
        sum += (arr[i]-mean)*(arr[i]-mean);
    }
    double variance = 0.0;
    variance = sum/(size-1);
    return variance;
    }
    else return 0;
}
double std_dev(double const arr[], int size){
    double mean = arr[0];
    if(size>1){
    for(int i =1; i<size;i++){
        mean += arr[i];
    }
    mean/=size;
    double sum = 0.0;
    for(int i = 0; i<size; i++){
        sum += (arr[i]-mean)*(arr[i]-mean);
    }
    double variance = 0.0;
    variance = sum/(size-1);
    double dev = 0.0;
    dev = sqrt(variance);
    return dev;
    }
    else return 0;
    
}