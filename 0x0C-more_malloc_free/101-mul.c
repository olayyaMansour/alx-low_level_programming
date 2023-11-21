#include <stdio.h>
#include <stdlib.h>

int is_digit(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char *num1;
    char *num2;
    int result;

    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    num1 = argv[1];
    num2 = argv[2];

    if (!is_digit(num1) || !is_digit(num2)) {
        printf("Error\n");
        return 98;
    }

    result = atoi(num1) * atoi(num2);
    printf("%d\n", result);

    return 0;
}

