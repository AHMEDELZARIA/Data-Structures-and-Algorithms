// Binary search program
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare array
    int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    
    // Calculate length of array
    long arraylength = sizeof(array) / sizeof(array[0]) - 1;
    
    // Declare positions
    int target = 0, start = 0, end = arraylength, mid = 0;
    
    // While loop that runs as long as the start element isn't greater than end element
    while (start <= end)
    {
        mid = (start + end) / 2; // Calculate new midpoint
        if (target == array[mid]) // If target is found at midpoint exit
        {
            printf("Found at element %i\n", mid);
            break;
        }
        else if (target != array[mid]) // If not, check whether the target is greater or smaller than midpoint and adjust start or end accordingly
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
