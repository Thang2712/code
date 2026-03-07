#include <stdio.h>
#include <stdlib.h>     // required for malloc() and free() 

// Function prototypes declaration
void insertionSort(int arr[], int n);
void printArray(int arr[], int size);

// Main function to request user input and display sorted array
int main()
{
    int n; 
    
    // Request user input for number of elements
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Request user input for array elements    
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    // Call insertion sort function
    insertionSort(arr, n);


    printf("Sorted array: \n");

    printArray(arr, n);
    // Free dynamically allocated memory
    free(arr);


    return 0;
    
}

// 1. Definition of insertion sort function
// Sorts an array using insertion sort algorithm(smallest to largest)
void insertionSort(int arr[], int n)
{
    int i, key, j;


    // Loop through elements from index 1 to n-1
    // The first element (arr[0]) is considered sorted
    for (i = 1; i < n; i++)
    {
        // 'key' is the element to be inserted into the sorted portion of the arr[0..i-1]
        key = arr[i];

        // 'j' is the index of the last element in the sorted portion
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];    // Shift element to the right
            j = j - 1;              // Check the next element on the left
        }

        // Insert the 'key' at its correct position
        arr[j + 1] = key;
    }
}

// Helper function to print the array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}