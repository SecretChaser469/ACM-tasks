
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LENGTH 256

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double sqrt_op(double value);
void handle_error(const char *message);
double evaluate_expression(const char *expression);
int precedence(char operator);
double apply_operator(double a, double b, char operator);
double evaluate(const char *expression, int *pos);
double parse_number(const char *expression, int *pos);

// Basic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        handle_error("Division by zero");
    }
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double sqrt_op(double value) {
    if (value < 0) {
        handle_error("Square root of negative number");
    }
    return sqrt(value);
}

// Error handling
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Parsing and evaluating expressions
int precedence(char operator) {
    switch (operator) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

double apply_operator(double a, double b, char operator) {
    switch (operator) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        case '^': return power(a, b);
        default:
            handle_error("Invalid operator");
            return 0; // Unreachable
    }
}

double parse_number(const char *expression, int *pos) {
    double value = 0;
    while (isdigit(expression[*pos])) {
        value = value * 10 + (expression[*pos] - '0');
        (*pos)++;
    }
    return value;
}

double evaluate(const char *expression, int *pos) {
    double values[MAX_EXPR_LENGTH];
    char operators[MAX_EXPR_LENGTH];
    int value_index = 0, op_index = 0;

    while (expression[*pos] != '\0') {
        char current = expression[*pos];
        if (isspace(current)) {
            (*pos)++;
            continue;
        }

        if (isdigit(current)) {
            values[value_index++] = parse_number(expression, pos);
        } else if (current == '(') {
            (*pos)++;
            values[value_index++] = evaluate(expression, pos);
        } else if (current == ')') {
            (*pos)++;
            break;
        } else if (strchr("+-*/^", current)) {
            while (op_index > 0 && precedence(operators[op_index - 1]) >= precedence(current)) {
                double b = values[--value_index];
                double a = values[--value_index];
                char op = operators[--op_index];
                values[value_index++] = apply_operator(a, b, op);
            }
            operators[op_index++] = current;
            (*pos)++;
        } else {
            handle_error("Invalid character in expression");
        }
    }

    while (op_index > 0) {
        double b = values[--value_index];
        double a = values[--value_index];
        char op = operators[--op_index];
        values[value_index++] = apply_operator(a, b, op);
    }

    return values[0];
}

double evaluate_expression(const char *expression) {
    int pos = 0;
    return evaluate(expression, &pos);
}

// Main function
int main() {
    
    char expression[MAX_EXPR_LENGTH];

    printf("Enter a mathematical expression: ");
    if (fgets(expression, sizeof(expression), stdin) == NULL) {
        handle_error("Failed to read input");
    }

    // Remove newline character if present
    size_t length = strlen(expression);
    if (length > 0 && expression[length - 1] == '\n') {
        expression[length - 1] = '\0';
    }

    double result = evaluate_expression(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
