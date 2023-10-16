#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 * Generate a random valid password for 101-crackme
 *
 * Return: Always 0
 */
int main(void)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int max_password_length = 20; // Maximum password length for 101-crackme
    char password[max_password_length + 1]; // +1 for the null terminator
    int i, random_index;

    srand(time(0)); // Seed for random number generation

    // Generate a random password using the charset
    for (i = 0; i < max_password_length; i++)
    {
        random_index = rand() % (sizeof(charset) - 1);
        password[i] = charset[random_index];
    }

    password[max_password_length] = '\0'; // Add null terminator

    printf("%s\n", password); // Print the generated password

    return 0;
}

