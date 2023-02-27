/*
You are given two integer arrays nums1 and nums2, 
sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.
*/


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int i, i1, i2;

    i1 = m - 1;
    i2 = n - 1;
    i = nums1Size - 1;
    
    while (i1 >= 0 && i2 >= 0) {
        if (nums1[i1] > nums2[i2]) {
            nums1[i] = nums1[i1];
            i--;
            i1--;
        } else {
            nums1[i] = nums2[i2];
            i--;
            i2--;
        }
    }
    
    while (i2 >= 0) {
        nums1[i--] = nums2[i2--];
    }
}