#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int i=0;
    int j=0;
    int sum=0;
    *returnSize=2;
    int *res= (int*)malloc(2*sizeof(int));
    
    for (i=0;i<numsSize;i++){
        for (j=i+1;j<numsSize;j++){
            
            sum=nums[i]+nums[j];
            if (target==sum){
                
                res[0]=i;
                res[1]=j;
                return res;
            }
        }
    }
    res[0]=-1;
    res[1]=-1;
    return res;
}