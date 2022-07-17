// Program that executes a linear search on an array
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Declare array
    int array[] = { 4, 6, 3, 25, 43, 50, 52, 61 };
    
    // Iterates through 8 times checking if the value 50 is present in array and states the position
    for (int i = 0; i < 8; i++)
    {
        if (array[i] == 50)
        {
            printf("Element found at position %i in the array.\n", i);
            return 1;
        }
    }
    // If value not found than it prints out this
    printf("Element not found.\n");
    return 1;
}
