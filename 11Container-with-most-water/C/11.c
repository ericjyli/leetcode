//Find the container with most water
#include <stdio.h>


int maxArea(int* height, int heightSize){
    int area=0;
    int heightUsed=0;
    int maxArea=0;
    
    for (int i=0;i<heightSize-1;i++){ //i is the starting point of the container
        for (int j=i+1;j<heightSize;j++){ //j is the ending point of the container
            if (height[j]>=height[i])
                heightUsed=height[i];
            if (height[i]>height[j])
                heightUsed=height[j];
            area=heightUsed*(j-i);
            if (maxArea<area){
                maxArea=area;
            }
            area=0;
        }
    }
    
    return maxArea;
}



//driver's code

int main(void){
    int height[]={1,8,6,2,5,4,8,3,7};
    int heightSize=9;
    maxArea(height,heightSize);
    printf("%d",maxArea(height,heightSize));

return 0;

}


