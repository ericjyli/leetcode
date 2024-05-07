from typing import List

def trap(height: List[int]) -> int:
    '''
    => left and right end there is no wall
    => at any point we store water is :
        water[i]= min (max_left_height,max_right_height)-arr[i];
    '''
    water = [0] * (len(height) + 2)
    max_left_height = [0] * len(height)
    max_left_height[0] = height[0]
    max_right_height = [0] * len(height)
    max_right_height[-1] = height[-1]
    
    for i in range (1, len(height)):
        max_left_height[i] = max(height[i], max_left_height[i - 1])
    for i in range(len(height) - 2, 0, -1):
        max_right_height[i] = max(height[i], max_right_height[i + 1])

    for i in range(1, len(height)):
        water[i] = min(max_left_height[i], max_right_height[i]) - height[i]
        
    sum = 0
    for i in range(len(water)):
        sum += water[i]
    
    return sum