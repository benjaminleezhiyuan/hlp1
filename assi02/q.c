/*
@file        q.c
@author      Benjamin Lee (benjaminzhiyuan.lee) 
@course      CSD1121F22
@section     A
@tutorial    Assignment 2
@date        10/09/22
@brief       This file contains definitions of 2 functions, draw_tree and draw_animal.         
*//*______________________________________________________________________*/

#include <stdio.h>

/*
@brief Prints out textual art consisting of 9 lines that represent a tree
*/

void draw_tree(void) {
    printf("    *\n");
    printf("   ***\n");
    printf("  *****\n");
    printf(" *******\n");
    printf("*********\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");
}

/*@brief Prints out textual art consisting of 10 lines that represent a cat saying out Hello Junior Coder!
in a speech bubble.*/

void draw_animal(void) {
    printf("  /\\     /\\\n");
    printf(" /  \\___/  \\\n");
    printf("(           )    -------\n");
    printf("(   '   '   )   / Hello  \\\n");
    printf("(     _     )  <  Junior  |\n");
    printf("(           )   \\ Coder! /\n");
    printf(" |         |     -------\n");
    printf(" |    |    |\n");
    printf(" |    |    |\n");
    printf("(_____|_____)\n");
}