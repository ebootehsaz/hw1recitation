#include <stdio.h>

long factorial(int n) {
    if (n < 0) {
        return -1; // Error condition for negative numbers
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    long result = factorial(number);
    if (result == -1) {
        printf("Factorial of a negative number is not defined.\n");
    } else {
        printf("Factorial of %d = %ld\n", number, result);
    }

    return 0;
}