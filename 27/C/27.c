/*
Leetcode question 27 
Remove the elements in the integer array nums

*/

int removeElement(int* nums, int numsSize, int val){
    
    if (numsSize == 0){
        return 0;
    }
    
    int i = 0;
    int j = numsSize - 1;

    
    while (j >= 0 && nums[j] == val){
        j--;
    }
    
    if (j < 0) {
        return 0;
    }
    
    while (i < numsSize && i <= j){
        if (nums[i] != val){
            i++;
        }
        
        else if (nums[i] == val){
            nums[i] = nums[j];
            nums[j] = val;
            j--;
        }
    }
    
    
    return i;
}



int main(){


    int nums[8] = {0,1,2,2,3,0,4,2};
    int numsSize = 8;
    int val = 2;

    int res = removeElement(nums,numsSize,val);

    return 0;


}
