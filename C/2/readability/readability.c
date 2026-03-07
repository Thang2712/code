#include <ctype.h>  // For isalpha() and isspace() functions
#include <math.h>   // For round() function
#include <stdio.h>  // For printf(), fgets()
#include <string.h> // For strlen() and strcspn()

// Custom function similar to CS50's get_string
void get_string(char *prompt, char *buffer, int size)
{
    printf("%s", prompt);               // Print the prompt message
    fgets(buffer, size, stdin);         // Safely read a line of input from the user
    buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline character
}

// Function declarations
int count_letters(char text[100000]);
int count_words(char text[100000]);
int count_sentences(char text[100000]);

int main(void)
{
    // Prompt the user for some text 
    char text[100000];
    get_string("Text: ", text, sizeof(text));

    // Count the number of letters, words, and sentences in the text 
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    // Compute L (average number of letters per 100 words) 
    float L = (float) letters / words * 100; 
    // Compute S (average number of sentences per 100 words)
    float S = (float) sentences / words * 100;

    //Coleman-Liau index formula: index = 0.0588 * L - 0.296 * S -15.8
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Rount the index to the nearest whole number
    int grade = round(index);

    // Print the grade level based on index
    if (grade < 1)
    {
        printf("Before Grade 1\n"); // For text simpler than Grade 1 level
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");      // For text more advanced than Grade 16
    }
    else 
    {
        printf("Grade %d\n", grade);// For Grade 1 to 16
    }
}

int count_letters(char text[100000])
{
    // Count the number of alphabetic characters in text
    int count = 0; 
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))   // CHeck if the character is a letter (a-z or A-Z)
        {
            count++;
        }
    }
    return count;   // Return total letter count
}

int count_words(char text[100000])
{
    // Count the number of words in text (words are separated by spaces)
    int count = 1; 
    for (int i = 1; i < strlen(text); i++)
    {
        if (isspace(text[i]))   // Check if the character is a space
        {
            count++;
        }
    }
    return count;   // Return total word count  
}

int count_sentences(char text[100000])
{
    // Count the number of sentences in text
    int count = 0; 
    for (int i = 0; i < strlen(text); i++)
    {
        // Sentences end with '.', '!' or '?' 
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;   // Return total sentence count
}