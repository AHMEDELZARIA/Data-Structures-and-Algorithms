// Bubble sort and binary search program
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Delcare array
    int array[] = { 123, 98721, 6525, 123, 1213, 213, 321, 23, 123123, 98243, 897293, 12311, 321312, 23223, 2132323 };
    
    // Calculate arraylength
    long arraylength = (sizeof(array) / sizeof(array[0])) - 1;
    
    // Prompt user for a target
    int target = get_int("Target value: ");
    
    // Loop that sorts the array by bubble sort 
    int swapcounter = -1;
    while (swapcounter != 0)
    {
        swapcounter = 0; // Reset swapcounter to zero after each round
        for (int i = 0; i < arraylength; i++) // Iterates through array "bubbling" the greatest value to the right each round
        {
            if (array[i] > array[i + 1])
            {
                int element = array[i];
                array[i] = array[i + 1];
                array[i + 1] = element;
                swapcounter++;
            }
        }
        arraylength = arraylength - 1; // Adjust arraylength to not account for the "bubbled" value
    }
    
    
    // reset arraylength again for binary search
    long arraylength2 = sizeof(array) / sizeof(array[0]) - 1;
    
    // Declare positions
    int start = 0, mid = 0, end = arraylength2;
    
    // While loop that runs as long as the current start position is not greater than the current end position 
    while (start <= end)
    {
        mid = (start + end) / 2; // Calculate mid point
        if (target == array[mid]) // If target is at midpoint, print message and exit
        {
            printf("%i was found at element %i.\n", target, mid);
            break;
        }
        else if (target != array[mid]) // If not, check if target is less than or greater than midpoint and adjust start or end accordingly
        {
            if (target > array[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}
