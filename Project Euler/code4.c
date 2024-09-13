#A palindromic number reads the same both ways. The largest palindrome made from the product of two 2 -digit numbers is  9009=91*99
#Find the largest palindrome made from the product of two  3-digit numbers.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(int number) {
    char str[7];
    sprintf(str, "%d", number); 
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int largest_palindrome = 0;

    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (is_palindrome(product) && product > largest_palindrome) {
                largest_palindrome = product;
            }
        }
    }

    printf("The largest palindrome made from the product of two 3-digit numbers is %d\n", largest_palindrome);
    return 0;
}
