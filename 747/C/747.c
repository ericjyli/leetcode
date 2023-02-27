/*
You are given an integer array nums 
where the largest integer is unique.

Determine whether the largest element in the array 
is at least twice as much as every other number in the array. 
If it is, return the index of the largest element, 
or return -1 otherwise.
*/

int dominantIndex(int* nums, int numsSize){

    int largest;
    int second;
    
    if (numsSize == 0 || numsSize == 1){
        return 0;
    }
    
    if (nums[0] >= nums[1]){
        largest = 0;
        second = 1;
    }
    
    else if (nums[0] < nums[1]){
        largest = 1;
        second = 0;
    }
    
    for (int i = 2; i < numsSize; i++){
        if (nums[i] > nums[largest]){
            second = largest;
            largest = i;
        }
        else if (nums[i] > nums[second]){
            second = i;
        }
    }
    
    if (nums[largest] >= 2 * nums[second]){
        return largest;
    }
    else {
        return -1;
    }
    
}