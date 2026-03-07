#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h> 


int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}


bool containsDuplicate(int* nums, int numSize)
{
    qsort(nums, numSize, sizeof(int), compare);

    int i; 
    for (i = 1; i < numSize; i++)
        if (nums[i] == nums[i - 1])
            return true;
    return false;
}

int main() 
{
    int size, i; 

    printf("enter the number of elements: "); 
    if (scanf("%d", &size) != 1 || size == 0)
    {
        printf("invalid size, please enter a positive size.");
        return 1;
    }

    int *arr = (int*)malloc(size * sizeof(int)); 
    if (arr == NULL)
    {
        printf("memory allocated failed \n"); 
        return 1;
    }

    printf("enter %d integers: \n", size); 
    for(i = 0; i < size; i++)
    {
        printf("elements %d: ", i + 1);
        scanf("%d", &arr[i]);

    }

    if (containsDuplicate(arr, size))
        printf("true\n");
    
    else
        printf("false\n");
}
