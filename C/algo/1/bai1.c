#include <stdio.h>
#include <stdlib.h>     // required for malloc() and free() 

int loop(int arr[], int n, int v);

int main(void)
{
     int n; 
    
    // Request user input for number of elements
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
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

    int v;
    // Request user input for the value to search
    printf("Enter the value to search for: ");  
    scanf("%d", &v);

    int result = loop(arr, n, v);
    if (result == -1)
        printf("Value not found in the array.\n");
    else
        printf("Value found in the array.\n");
}

int loop(int arr[], int n, int v) 
{ 
    int i, j, temp; 
    for (i = 0; i < n; i++) 
    
        if (arr[i] == v)
           return 0;
    return -1;
}
