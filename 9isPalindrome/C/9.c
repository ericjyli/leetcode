#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPalindrome (int x){
    if (x < 0){
        return false;
    }
    
    if (x < 10){
        return true;
    }
    int digit = 0;
    int reversed = x;
    int num = 0;
    int prevNums;  
    bool first = true;
    
    while (reversed > 0){
        digit++;
        reversed = reversed / 10;
    }
    
    reversed = 0;
    
    int i = 0;
    
    while (digit > 0){
        num = x / (pow(10,(digit-1)));
        if (!first){
            prevNums = num /10; 
            prevNums = prevNums * 10;
            num = num - prevNums;
        }

        first = false;
        reversed = reversed + num * (pow(10,i));
        i++;
        digit--;
        
    }
    
    if (reversed == x)
        return true;
    else
        return false;
}

int main (void){

    int x = 0;
    printf("The number you enter is: ");
    scanf(" %d",&x);
    bool p = isPalindrome(x);
    if (p)  printf ("Yes!");
    if (!p)     printf("No!");

    return 0;
}
