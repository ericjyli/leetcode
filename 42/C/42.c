//leetcode Question 42
//Trapping rain water

#include <stdbool.h>
#include <stdio.h>

int trap(int* height, int heightSize){
    int i, j;
    bool end = false;
    int h = 0;
    i = 0;
    while (height[i] == 0){
        i++;
    }
    //i is at the first non-zero place
    int temp;
    j = i;
    while (!end){
        j++;
        while (height[j] < height[i] && j < heightSize){
            j++;
        }
        if (j > heightSize || j == heightSize){
            break;
        }
        //j is on the other side
        
        temp = height[i];
        //temp is the lower side 
        
        while (i < j){
            if (temp - height[i] > 0){
                h += temp - height[i];
            }
            
            i++;
        }
        //i reaches j
        
    }
    return h;
}

int main(){
    int heightSize = 12;
    int height[]= {0,1,0,2,1,0,1,3,2,1,2,1};

    int fuck = trap(height,heightSize);
    printf("%d\n",fuck);

    return 0;
}
