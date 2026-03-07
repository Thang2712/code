#include <ctype.h>  // For isdigit(), isupper(), islower()
#include <stdio.h>  // For printf(), fgets()
#include <stdlib.h> // For atoi() (string -> int conversion)
#include <string.h> // For strlen(), strcspn()

void get_string(char *prompt, char *buffer, int size)
{
    printf("%s", prompt);               // Print the prompt message
    fgets(buffer, size, stdin);         // Safely read a line of input from the user
    buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline character
}


int main(int argc, char *argv[])
{
    // Check that the user provided exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");    // Instruction for correct usage
        return 1;                           // Exit with error code
    }   

    // Verify that the argument (key) is a positive number (contains only digits)
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            return 1;   // Exit if argument contains non-digit characters
        }
    }

    // Convert the key from string to integer
    int key = atoi(argv[1]); 


    // Prompt the user for plaintext input
    char plaintext[100000];
    get_string("plaintext: ", plaintext, sizeof(plaintext));

    // Begin priting ciphertext
    printf("ciphertext: ");

    // Loop through each character of the plaintext
    for(int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];  // Current character 

        // Encrypt uppercase letters
        if (isupper(c))
        {
            // Shift character by key, wrap around using module 26
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        // Encrypt lowercase letters
        else if (islower(c))
        {
            // Same logic but relative to 'a'
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        // Leave non-alphabectic characters unchanged
        else 
        {
            printf("%c", c);
        }
    }
    printf("\n");   // End ciphertext with a newline
    return 0;       // Sucessful execution
}

