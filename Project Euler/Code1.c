#if we list all the natural numbers below 10 that are multiples of 3or 5, we get 3,5,6 and 9. The sum of these multiples is 23.Find the sum of all the multiples of 3 or 5 below 1000

#include <stdio.h>

int main() {
    int limit = 1000; 
    int sum = 0;

    
    for (int i = 1; i < limit; i++) {
      
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i; 
        }
    }

    printf("The sum of natural numbers below %d that are multiples of 3 or 5 is %d\n", limit, sum);

    return 0;
}
