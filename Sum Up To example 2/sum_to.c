#include <stdio.h>
#include <stdlib.h>

int sum_up_to(int n) {
    int array[n];
    int sum = 0;
    for (int i = 0; 0 <= i <= n; i++) { 
        array[i] = i;
        sum += array[i];
    }
    return sum;
}

int main() {
    int number = 10;
    int result = sum_up_to(number);
    printf("Sum up to %d is %d\n", number, result);
    return 0;
}
