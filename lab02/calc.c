/*!
@file       calc.c
@author     Benjamin Lee (benjamizhiyuan.lee)
@course     RTIS
@section    A
@tutorial   02
@date       09/09/22
@brief      This file contains the definition of the functions squared, cubed and minus.
*/
// provide the definition of function squared
// that matches the declaration in calc.h ...

#include "calc.h"

int squared(int i) {
    i=i*i;
    return i;
}
// provide the definition of function cubed
// that matches the declaration in calc.h ...
double cubed(double d) {
    d=d*d*d;
    return d;
}
// provide the definition of function minus
// that matches the declaration in calc.h ...
double minus(double x) {
    return -x;
}

