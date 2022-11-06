/*
@q.c 
@Benjamin Lee (benjaminzhiyuan.lee)
@CSD1121F22 @todo which course is this source file meant for?
@Section A
@Lab 03 @todo provide Tutorial #
@16/09/22 @todo provide date on which you created the file
@brief
This file contains a collection of functions that takes in the values wall length and tile
width to calculate how many pairs of blackand white tiles and number of tiles needed to cover
a wall with a size of gap at the end.
It also contains functions that takes in the price of an item and the denomination of note used
to pay to output the change in terms of loonies, half-loonies, quarters, dimes, nickels and pennies.
*//*______________________________________________________________________*/

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function tile to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition of function tile that
// matches the declaration in q.h ..

void tile(double wl,double tw){

   double pairs = (wl-tw)/(2*tw); // calculates how many pairs of black and white tiles
   int realpairs;
    realpairs = (int)pairs; // converts pairs from double to integer value
   int tiles = 1 + 2*(realpairs); // calculates total number of tiles
   double gap = (wl - (tiles * tw))/2; // calculates size of the gap 

    printf("%-12s%.2lf%-13s%.2lf\n","Wall length: ",wl," | Tile width: ",tw);
    printf("%s%d\n","Number of tiles: ",tiles);
    printf("%s%.2lf\n","Gap at each end: ",gap);
}

// Add documentation [for yourself and not for grading] for function dispense_change ...

// @todo: Provide the definition of function dispense_change that
// matches the declaration in q.h ...
void dispense_change (void){

    int pricedollars, pricecents, billdollars; //int value of item price in dollars and cents
    scanf("%d.%d %d", &pricedollars, &pricecents, &billdollars); //reads input for item price and bill value

    int purchase=pricedollars*100+pricecents; //calculate total change needed to be returned
    int balance=billdollars*100;
    balance=balance-purchase; 

    int loonies = balance/100; //calculate number of loonies 
    balance=balance-loonies*100;

    int half_loonies = balance/50;//calculate number of half-loonies
    balance=balance-half_loonies*50;

    int quarters = balance/25; //calculate number of quarters
    balance=balance-quarters*25;

    int dimes = balance/10; // calculate number of dimes
    balance=balance-dimes*10;

    int nickels = balance/5; //calculate number of nicklels
    balance=balance-nickels*5; 

    int pennies = balance; //calculate number of pennies

    //prints total amount of loonies, half-loonies, quarters, dimes, nickels and pennies.
    printf("%d%s%d%s%d%s%d%s%d%s%d%s\n", loonies," loonies + ",half_loonies," half-loonies + ",quarters," quarters + ",dimes," dimes + ",nickels," nickels + ",pennies," pennies");
}  