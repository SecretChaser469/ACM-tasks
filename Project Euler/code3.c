#the prime factors of 13195 are 5,7,13,29. What is the largest prime factor of the number 600851475143

#include <stdio.h>
long largest_prime_factor(long n) {
    long max_prime = -1;
    while (n % 2 == 0) {
        max_prime = 2;
        n /= 2;
    }

    for (long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_prime = i;
            n /= i;
        }
    }
    if (n > 2) {
        max_prime = n;
    }

    return max_prime;
}

int main() {
    long number = 600851475143;
    long result = largest_prime_factor(number);
    printf("The largest prime factor of %ld is %ld\n", number, result);
    return 0;
}
