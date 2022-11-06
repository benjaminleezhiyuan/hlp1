// prototypes for functions called in function main

#include <stdio.h>

void draw_tree(void);   //defined in q.c
void draw_animal(void); //defined in q.c

int main(void) {
    draw_tree();
    draw_animal();
    return 0;
}
