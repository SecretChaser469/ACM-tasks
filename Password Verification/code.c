#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to validate the password
int validate_password(const char *password) {
    // List of forbidden passwords
    const char *forbidden_passwords[] = { "A1b#cD3e", "Xy4$Zz7!", "P@ssw0rd", "M!n3r4L^", "T7r$eN8f" };
    int forbidden_count = sizeof(forbidden_passwords) / sizeof(forbidden_passwords[0]);

    // Check if password matches any of the forbidden passwords
    for (int i = 0; i < forbidden_count; i++) {
        if (strcmp(password, forbidden_passwords[i]) == 0) {
            printf("Error: Password is not allowed.\n");
            return 0;
        }
    }

    // Check if password length is at least 8
    if (strlen(password) < 8) {
        printf("Error: Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check if password starts with a number or special character
    if (!isalpha(password[0])) {
        printf("Error: Password should not start with a number or special character.\n");
        return 0;
    }

    // Check for at least one uppercase letter, one lowercase letter, and one special character
    int has_upper = 0, has_lower = 0, has_special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (ispunct(password[i])) has_special = 1;
    }

    if (!has_upper) {
        printf("Error: Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!has_lower) {
        printf("Error: Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!has_special) {
        printf("Error: Password must contain at least one special character.\n");
        return 0;
    }

    // If all conditions are satisfied
    printf("Success: Password is valid!\n");
    return 1;
}

int main() {
    char password[100];
    char choice;

    printf("=== Welcome to the Password Validator! ===\n");

    do {
        printf("\nPlease enter a password to validate: ");
        scanf("%s", password);

        validate_password(password);

        printf("\nWould you like to try another password? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Password Validator! Goodbye!\n");
    
    return 0;
}
