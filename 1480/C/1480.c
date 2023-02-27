/*
Given an array nums. 
We define a running sum of an array as 
runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/


#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    
    int *runningSum = malloc(numsSize * sizeof(int));
    
    runningSum[0] = nums[0];
    for (int i = 1; i < numsSize; i++){
        runningSum[i] = runningSum[i-1] + nums[i];
    }
    
    *returnSize = numsSize;
    
    return runningSum;

}
