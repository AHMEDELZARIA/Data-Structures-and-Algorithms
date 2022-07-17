// Selection sort program
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare array
    int array[10];
    
    for (int i = 0; i < 10; i++)
    {
        array[i] = get_int("Number %i: ", i + 1);
    }
    
    
    // Calculate arraylength
    long arraylength = sizeof(array)/sizeof(array[0]);
    
    // Loop to sort array by selection sort algorithm
    for (int i = 0; i < arraylength - 1; i++)
    {
        int min = i; // Set the minimum to the current i value
        for (int j = i + 1; j < arraylength; j++) // Set j greater than i by 1
        {
            if (array[j] < array[min]) // If the current array value (array[j]) is smaller than minimum (array[i]), the minimum index is updated to j
            {
                min = j;
            }
        }
        // swap the array[min] with array[i]
        int element = array[i];
        array[i] = array[min];
        array[min] = element;
    }
    
    // Print out sorted array
    printf("\nSorted: %i %i %i %i %i %i %i %i %i %i\n", array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7], array[8], array[9]);
}
