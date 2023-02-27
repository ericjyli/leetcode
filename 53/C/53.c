/*
Given an integer array nums, find the 
subarray
with the largest sum, and return its sum.
*/

#include <limits.h>

int maxSubArray(int* nums, int numsSize){

    int sum = 0;
    int max = INT_MIN;
    
    for (int i = 0; i < numsSize; i++){
        
        if (sum >= 0){
            sum += nums[i];
        }
        
        else {
            sum = nums[i];
        }
        
        if (sum > max){
            max = sum;
        }
    }
    
    return max;
}