#include <stdio.h>

char numtochar(float avg);

int main()
{
    float average;
    do
    {
        printf("enter average ");
        scanf("%f", &average);
    } while (average < 0 || average > 10);

    printf("Results: %c\n", numtochar(average));
    return 0;
}

char numtochar(float avg)
{
    char character;
    if (avg >= 8.5)
        character = 'A';
    else 
        if (avg >= 7.0)
            character = 'B';
        else 
            if (avg >= 5.5)
                character = 'C';
            else
                 if (avg >= 4.0) 
                    character = 'D';
                else 
                    character = 'F';
    return character; 

}