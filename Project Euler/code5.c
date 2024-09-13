#2520 is the smallest number that can be divided by each of the numbers from  1 to 10 without any remainder.
#What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int result = 1;
    for (int i = 1; i <= 20; i++) {
        result = lcm(result, i);
    }
    
    printf("The smallest number that is evenly divisible by all of the numbers from 1 to 20 is %d\n", result);
    
    return 0;
}
