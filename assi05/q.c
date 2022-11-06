/*
q.c
Benjamin Lee (benjaminzhiyuan.lee)
CSD1121F22
Section A
Assignment 05
30/09/22
Brief -
This file contains definitions for functions trapezoid_pi,montecarlo_pi and leibniz_pi.
trapezoid_pi calculates pi by using rectangles in a quadrant of a circle.
montecarlo_pi calculates pi using probability of random point landing inside circle of x radius compared to square of 2x length,
leibniz_pi calculates pi by using an infinite series of additions and subtractions to approximate pi.
*/
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "q.h"
// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...
double trapezoid_pi(int num_of_rects)
{   
    int reps = 1;
    double w = 2.0/num_of_rects; //calculate the width
    double pi_trap=0.0;

    for(int i=1;i<=num_of_rects;i+=1){
        double x = (w*reps)-(w/2);
        double h = sqrt(((4)-(x*x)));
        pi_trap += h;
        reps +=1;
    }
    pi_trap = pi_trap * w;
    return pi_trap;
}

double montecarlo_pi(unsigned int seed, int num_of_trails)
{
    srand(seed);
    int reps = 0;
    double pi_monte=0.0,x,y,distance;
    for(int i=1;i<=num_of_trails;i+=1){ 

    x = (double)rand() / RAND_MAX;//gives random float between 0-1
    y = (double)rand() / RAND_MAX;//gives random float between 0-1
    distance = x*x + y*y; //calculates distance of random point to center of circle.
    if (distance<=1) reps += 1; //checks if the random point is within the circles area.
}
    pi_monte = (double) reps/num_of_trails*4;
    return pi_monte;
}
double leibniz_pi(int num_elements){
    double sum=0.0,calculation;
    for(int i=0;i< num_elements;i++)
 {
  calculation = pow(-1, i) / (2*i+1);// pow(-1,i) flips 1 from positive to negative for every iteration.
  sum += calculation;                //(2*i+1) gives us the denominator for each iteration.
 }
 double pi_leib = 4 * sum;
 return pi_leib;
}


