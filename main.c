#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char type;
    size_t n;

    printf("Do you want to enter (i)nteger or (f)loat values? ");
    if (scanf(" %c", &type) != 1 || (type != 'i' && type != 'I' && type != 'f' && type != 'F')) {
        fprintf(stderr, "Invalid choice. Exiting.\n");
        return 1;
    }

    printf("How many values do you want to enter? ");
    if (scanf("%zu", &n) != 1) {
        fprintf(stderr, "Invalid number.\n");
        return 1;
    }
    if (n == 0) {
        printf("Nothing to do (n = 0).\n");
        return 0;
    }

    /*
    TODO
    Implement so that the user can enter the amount of specified values of specified type!
    Only positve values are allowed! --> valuse > 0
    Print out the array of values after the user is done on the same row!
    */

    return 0;
}