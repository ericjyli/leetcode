/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int n=nums1Size+nums2Size;
        double nums3[n];
        int i,j,k;
        i=j=k=0;
        while(i<nums1Size && j<nums2Size){
            if(nums1[i]<nums2[j]){
                nums3[k]=nums1[i];
                i++;
                k++;
            }
            else{
                nums3[k]=nums2[j];
                k++;
                j++;
            }
        }
        for(;i<nums1Size;i++){
            nums3[k]=nums1[i];
            k++;
        }
        for(;j<nums2Size;j++){
            nums3[k]=nums2[j];
            k++;
        }
        if(n%2==0)  
            return ((nums3[n/2]+nums3[n/2-1])/2);
        else
            return nums3[n/2];
        
        
        return -1;
        
}
