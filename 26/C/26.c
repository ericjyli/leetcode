/*
Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element 
appears only once. 
The relative order of the elements should be kept the same.
*/

#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize){

    int i = 0;
    int j = 0;
    if (nums == NULL){
        return 0;
    }
    
    while (i < (numsSize-1)){
        if (nums[i+1] == nums [i]){
            i++;
        }
        else {
            nums [j] = nums[i];
            i++;
            j++;
        }
    }
    
    nums[j] = nums[i];
    j++;

    return j;
}