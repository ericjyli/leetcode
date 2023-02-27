/*
Given an array of integers arr, 
return true if and only if it is a valid mountain array.
*/


#include <stdbool.h>

bool validMountainArray(int* arr, int arrSize){
    if (arrSize < 3) return false;
    
    int i = 0;
    while (i < (arrSize-1) && arr[i+1] > arr[i]){
        i++;
    }
    
    if (i == (arrSize-1)||i == 0)   return false;
    
    while (i < (arrSize-1) && arr[i+1] < arr[i]){
        i++;
    }
    
    if (i == (arrSize-1))   return true;
    else return false;
}
