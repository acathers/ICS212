/* Name: Anthony Cathers
 * Core Concept: use recursion in a C program
 * Date Created: 11/20/2018
 */

#include <stdio.h>


//function prototypes
int addTogether(int);
int power(int, int);
void displayMenu();

int main() {

int choice;

    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){

            case 1:{
                printf("Enter a integer to sum digits: ");
                int num;
                scanf("%d", &num);
                int result = addTogether(num);
                printf("\nSum of digits is: %d\n", result);
                break;
            }
            case 2: {
                int base;
                int exponent;
                printf("Enter base: ");
                scanf("%d", &base);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                int result = power(base, exponent);
                printf("\nxponent evaluated is: %d\n", result);
                break;
            }
            default: {
                printf("\nInvalid selection, please try again\n");
            }
        };


    }while(choice != 3);


    return 0;
}

int addTogether(int num){

    if(num == 0){ //return 0 if initially 0 or base case is reached
        return 0;
    }

        return (num % 10 + addTogether(num / 10));
}

/*how addTogether works
 * printf("Value is %i:", addTogther(123);
 *
 * enters addTogether with num = 321
 *
 * extract right digit by num % 10 which equals 1
 * call addTogether with right digit removed by / 10 so addTogether(12);
 *
 * currently on stack 1 + addtogther(12);
 *
 * extract right, 2 then call again addTogther(1);
 *
 * currently on stack 1 + 2 + addTogether(1);
 *
 * extract right, 1, call addTogether(0)
 *
 * currently on stack 1 + 2 + 3 + addTogether(0)
 *
 * base case is reached since 0, goes back up stack returns 1+2+3+0;
 *
 */

int power(int base, int exponent){
    if(base==0){
        return 0;
    }

    if(exponent == 0){
        return 1;
    }
    return base * power(base, --exponent);
}

void displayMenu(){
    printf("\n1. Sum digits of integer\n");
    printf("2. Evaluate exponent\n");
    printf("3. Quit\n");
    printf("Selection: ");
}

/*
 * How power() works
 *
 * follows same method as above, except multiples base and uses exponent as a counter.
 * returns 1 if exponent = 0 as to not multiply by 0 and correct calculation if exponent is initially 0
 */


