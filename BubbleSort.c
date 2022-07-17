// Program that bubble sorts an array
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare arrays
    int array[] = { 21, 2, 5, 5, 78, 3, 11 };
    // Calculate length of array
    long arraylength = (sizeof(array)/sizeof(array[0])) - 1 ;
    
    // Set swap counter to a non-zero integer
    int swapcounter = -1;
    
    // Loop that iterates through array sorting elements as long as swapcounter is not equal to 0
    while (swapcounter != 0)
    {
        swapcounter = 0; // Reset swap counter to zero each round
        for (int i = 0; i < arraylength; i++) // iterates through each round swapping adjacent pairs if necessary and increments swap counter by 1
        {
            if (array[i] > array[i + 1])
            {
                int element = array[i];
                array[i] = array[i + 1];
                array[i + 1] = element;
                swapcounter++;
            }
        }
        arraylength = arraylength - 1; // Adjust the checking range
    }
    
    printf("%i %i %i %i %i %i %i\n", array[0], array[1], array[2], array[3], array[4], array[5], array[6]);
}
