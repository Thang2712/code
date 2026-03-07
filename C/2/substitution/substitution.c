#include <ctype.h>      // For isdigit(), isupper(), islower()
#include <stdbool.h>    // For bool, true, false
#include <stdio.h>      // For printf(), fgets()
#include <stdlib.h>     // For exit codes
#include <string.h>     // For strlen(), strcspn()

// Define string type (same as CS50's "string")
typedef char *string;

// Function prototypes
bool is_valid_key(string key);
bool has_repeats(string key);

// Custom get_string function (replacement for CS50' get_string)
void get_string(char *prompt, char *buffer, int size)
{
    printf("%s", prompt);               // Print the prompt
    fgets(buffer, size, stdin);         // Read user input
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline at the end
} 

int main(int argc, string argv[])
{
    // Ensure the user provides exactly 1 command-line arguement (the key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];   // Store the provided key 

    // Validate the key (must be 26 unique alphabetic characters)
    if (!is_valid_key(key))
    {
        return 1;   // Exit if invalid
    }

    // Prompt the user for plaintext input
    char plaintext[10000];
    get_string("plaintext: ", plaintext, sizeof(plaintext));

    printf("ciphertext: ");

    // Loop through each character of the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            // Find alphabetical inxdex (0-25)
            int index = c - 'A';
            // Substitute using key, covert back to uppercase
            printf("%c", toupper(key[index]));
        }

        else if (islower(c))
        {
            // Find alphabetical index (0-25)
            int index = c - 'a';
            // Substitute using key, convert back to lowercase
            printf("%c", tolower(key[index]));
        }

        else 
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", c);
        }
    }

    printf("\n");   // End ciphertext with newline
    return 0;
    
}

// Function to validate the key 
bool is_valid_key(string key)
{
    // Must contain exactly 26 characters 
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return false;
    }

    // Every character must be alphabetic
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }
    }

    // Check for repeated letters (case-insensitive)
    if (has_repeats(key))
    {
        printf("Key must not contain repeated characters.\n");
        return false;
    }

    return true;    // Key is valid
}


// Function to check for duplicate characters in the key
bool has_repeats(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {   
            // Compare case-insensitive
            if (toupper(key[i]) == toupper(key[j]))
            {
                return true;    // Duplicate found
            }
        }
    }

    return false;   // No duplicates
}