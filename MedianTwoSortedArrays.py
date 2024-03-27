import sys

def median(x,y):
    # Ensure we wdo binary search on smaller array for better complexity
    if (len(x) > len(y)): return median(y,x)
    
    x_len = len(x)
    y_len = len(y)
    low = 0
    high = x_len
    
    # Run a binary search on smaller array
    while (low <= high):
        p_x = (low + high) // 2 # Smaller array lefsadt partition size
        p_y = (x_len + y_len + 1) // 2 - p_x # Larger array left partition size  

        max_left_x = x[p_x - 1] if (p_x > 0) else float('-inf')
        max_left_y = y[p_y - 1] if (p_y > 0) else float('-inf')
        min_right_x = x[p_x] if (p_x != x_len) else sys.maxsize
        min_right_y = y[p_y] if (p_y != y_len) else sys.maxsize

        # Check to see if left partition has smallest elements in x U y
        if (max_left_x <= min_right_y):
            
            if (max_left_y <= min_right_x):
                return max(max_left_x, max_left_y)
            else:
                low = p_x + 1

        else:
            high = p_x - 1

# Test input
x = [1]
y = [1, 1, 2, 2, 2, 2]
print(median(x,y))


