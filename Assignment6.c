/* Name: Anthony Cathers
 * Core Concept: use structures in a C program
 * Date Created: 10/8/2018
 */
#include <stdio.h>

int main() {
    int v1 = 3;
    int v2 = 5;
    int* p1 = &v1;
    int* p2 = &v1;
    int* p3 = &v2;

    printf("v1 memory address is %i, value for v1 is %i ", &v1, v1);
    printf("\nv2 memory address is %i, value for v2 is %i ", &v2, v2);
    printf("\nfirst pointer value %i", *p1);
    printf("\nsecond pointer value %i", *p2);
    printf("\np1 memory location %i", p1);
    printf("\np2 memory location %i", p2);

    v1 = 7;

    printf("\nv1 value is now %i", v1);
    printf("\np1 memory location %i", p1);
    printf("\np2 memory location %i", p2);

    *p3 = 1;

    printf("\np3 memory location %i", p3);
    printf("\nv2  value is %i", v2);

    return 0;
}