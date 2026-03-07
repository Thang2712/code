#include <stdio.h> 
#include <string.h> 

#define N_BITS 8
void char_to_binary(char character, int binary_array[]);
void binary_plus(int A[], int B[], int C[], int n);

int main()
{
    char char1, char2; 

    printf("Enter first character: ");
    scanf(" %c", &char1);
    printf("Enter second character: ");
    scanf(" %c", &char2);
    
    int A[N_BITS];
    int B[N_BITS];
    int C[N_BITS];

    char_to_binary(char1, A);
    char_to_binary(char2, B);

    printf("\n------------------\n");
    printf("Char '%c' (ASCII %d) in binary: ", char1, (int)char1);
    for (int i = 0; i < N_BITS; i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
    printf("Char '%c' (ASCII %d) in binary: ", char2, (int)char2);
    for (int i = 0; i < N_BITS; i++)
    {
        printf("%d", B[i]);
    }   
    printf("\n");

    binary_plus(A, B, C, N_BITS);
    printf("\nBinary sum(%d-bit): ", N_BITS + 1);
    for (int i = 0; i < N_BITS; i++)
    {
        printf("%d", C[i]);
    }
    printf("\n"); 

    printf("Decimal sum: %d + %d = %d\n", (int)char1, (int)char2, (int)char1 + (int)char2);

    return 0; 
}


void char_to_binary(char character, int binary_array[])
{
    int value = (int)character; 

    for (int i = 0; i < N_BITS; i++)
    {
        binary_array[N_BITS - 1 - i] = (value >> i) & 1;
    }
}


void binary_plus(int A[], int B[], int C[], int n)
{
    int carry = 0;
    for (int i = N_BITS - 1; i >= 0; i--)
    {
        int sum = A[i] + B[i] + carry;
        C[i] = sum % 2;
        carry = sum / 2;
    }

    C[0]= carry;
}