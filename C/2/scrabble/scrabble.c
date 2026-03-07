#include<ctype.h> // For character classification functions (isupper, islower)
#include<stdio.h> // For input/output functions(printf, fgets)
#include<string.h> // For string manipulation functions (strlen, strcspn)

// Array containing the points for each letter in Scrabble
// Index 0 = 'A' or 'a', index 1 = 'B' or 'b'
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function declaration
int compute_score(char word[]);

int main(void)
{
    // Prompt the user for the first word
    char word1[100];
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin); // Read a line of input from the user
    word1[strcspn(word1, "\n")] = 0; // Remove the trailing newline character
    

    // Prompt the user for the second word
    char word2[100];
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = 0;

    // Compute the score of each word 
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    
    // Determine and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else 
    {
        printf("Tie!\n");
    }
}

// Function to comput the Scrabble score of a given word
int compute_score(char word[])
{
    // Initialize total score
    int score = 0; 

    // Get the length of the word
    int len = strlen(word);

    // Compute score for each character
    // Loop through each character in the word 
    for (int i = 0, len = strlen(word);i < len; i++)
    {
        // If the character is an uppercase letter
        if (isupper(word[i]))
        {
            // Subtract 'A' to get the correct index in POINTS
            score += POINTS[word[i] - 'A'];
        }
        // If the character is a lowercase letter
        if (islower(word[i]))
        {
            // Subtract 'a' to get the correct index in POINTS
            score += POINTS[word[i] - 'a'];
        }
    }
    return score; // Return the computed score 
}



//'C' - 'A' = 67 - 65 = 2
// POINTS[2] = 3  // Score for C
