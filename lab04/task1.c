// @todo: Add a file documentation header as explained in the specs ...

#include <stdio.h>

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

void print_line (int index, int denomination, int rest)
{
   
    printf("| %-2d | %9d.%02d | %5d |\n", index, denomination/100,denomination%100, rest);
}

void break_down(int cents)
{
    int bal, rest;

    printf("+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");

    bal = cents;

    rest = bal/10000;
    bal -= rest*10000;
    print_line(1,10000,rest);

    rest = bal/5000;
    bal -= rest*5000;
    print_line(2,5000,rest);

    rest = bal/1000;
    bal -= rest*1000;
    print_line(3,1000,rest);

    rest = bal/500;
    bal -= rest*500;
    print_line(4,500,rest);

    rest = bal/200;
    bal -= rest*200;
    print_line(5,200,rest);

    rest = bal/100;
    bal -= rest*100;
    print_line(6,100,rest);

    rest = bal/50;
    bal -= rest*50;
    print_line(7,50,rest);

    rest = bal/20;
    bal -= rest*20;
    print_line(8,20,rest);

    rest = bal/10;
    bal -= rest*10;
    print_line(9,10,rest);

    rest = bal/5;
    bal -= rest*5;
    print_line(10,5,rest);

    rest = bal;
    print_line(11,1,rest);

    printf("+----+--------------+-------+\n");

}

int main(void)
{
    printf("Please enter total value: "); //Prompts user for value input.
    int d, c, cents, check = scanf("%d.%d",&d,&c);

    if (check != 2)// checks that value is entered correctly.
    {
        printf("You did not type in the correct format in terms of dollars and cents.\n");
        scanf("%d.%d",&d,&c);
    }

     else if (d<0) //checks if dollar is negative
    {
        printf("The dollars part specified must be non-negative.\n");
        scanf("%d.%d",&d,&c);
    }

    else if (c<0 || c>99) //checks if cents are valid
    {
        printf("The cents part specified must be between 0...99 (inclusive).\n");
        scanf("%d.%d",&d,&c);
    }
    else 
    {
        printf("\n");
        cents = d*100 + c; //calculates value in terms of cents
        break_down(cents); // calls function break_down;
    }

    return 0;

}
// For each function -

// Add documentation [for yourself and not for grading] for the function ...



// @todo: Provide the definition of the function that
// matches the declaration in q.h ...