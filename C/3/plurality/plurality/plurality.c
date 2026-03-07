#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;   // Define 'string' as an alias for 'char *'
//--------------------------
// Custom input functions
//--------------------------



// Function to safely read an integer from the user
int get_int(const char *prompt)
{
    int number;         // Variable to store the parsed integer
    char buffer[100];   // Temporary buffer to hold raw user input

    while (true)        // Keep asking until user enters a valid integer
    {
        printf("%s", prompt);   // Display prompt message

        // Read input as a string (safer than scanf)
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // Try to convert the input string into an integer
            char *endptr;   // Pointer to track where parsing stops
            number = strtol(buffer, &endptr, 10);

            // If 'endptr' stops at newloine or end of string -> valid integer
            if (*endptr == '\n' || *endptr == '\0')
            {
                return number;      // Return the parsed integer
            }
            else
            {
                // If input is not a valid integer, show error and retry
                printf("Invalid input. Please enter an integer.\n");
            }
        }
    }
}


// Function to safely read a string from the user
char *get_string(const char *prompt)
{
    char buffer[1024]; // Temporary buffer for raw input
    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return NULL; // Return NULL if reading fails
    }

    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = '\0';

    // Allocate dynamic memory for the exact string sizee
    char *str = malloc(strlen(buffer) + 1);
    if (str == NULL)
    {
        return NULL; // Return NULL if memory allocation fails
    }

    strcpy(str, buffer);    // Copy buffer into allocated memory

    return str;     // Return dynamically allocated string
}

//--------------------------
// Election-related constants & structures
//--------------------------


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;    // Candidate's name
    int votes;      // Number of votes the candidate has received
} candidate;

// Array to store all candidates
candidate candidates[MAX];

// Number of candidates participating
int candidate_count;

// Function prototypes
bool vote(string name);     // Record a vote for a candidate
void print_winner(void);    // Print the election winner(s)


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // Number of candidates (excluding program name)

    if (candidate_count > MAX)  // Check if too many candidates
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Populate the candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];   // Assign candidate name
        candidates[i].votes = 0;            // Initialize votes to 0
    }

    // Get number of voters from user
    int voter_count = get_int("Numbers of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // Compare input with candidate names
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)  // Exact string match
        {
            candidates[i].votes++;  // Increase vote count
            return true;            // Return true if vote is valid
        }
    }
    return false;       // Return false if no candidate matched
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int max_votes = 0;  // Track the highest vote count found

    // Step 1: Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Step2: Print all candidates who have the maximum number of votes
    // (handles ties correctly)
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
