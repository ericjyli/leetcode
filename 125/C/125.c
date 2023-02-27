/*
A phrase is a palindrome if, 
after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/



#include <stdbool.h>
#include <string.h>
#include <stdio.h>


bool isPalindrome(char * s){
    int back = strlen(s) - 1;
    int front = 0;
    for (int i = 0; i <= back; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a'; 
        }
    }
    
    while (back > front) {
        while ((front < (back + 1)) && ((s[front] < 'A') 
                || ((s[front] > 'Z') && (s[front] < 'a')) || (s[front] > 'z'))
                &&(s[front] != '0')&&(s[front] != '1')&&(s[front] != '2')&&(s[front] != '3')
                &&(s[front] != '4')&&(s[front] != '5')&&(s[front] != '6')&&(s[front] != '7')
                &&(s[front] != '8')&&(s[front] != '9')){
            front++;
        }
        while ((back >= 0) && ((s[back] < 'A') || ((s[back] > 'Z') && (s[back] < 'a')) 
                ||(s[back] > 'z'))&&((s[back] != '0')&&(s[back] != '1')&&(s[back] != '2')
                && (s[back] != '3')&&(s[back] != '4')&&(s[back] != '5')&&(s[back] != '6')
                &&(s[back] != '7')&&(s[back] != '8')&&(s[back] != '9'))){
            back--;
        }
        

        if (front >= back){
            return true;
        }
        
        if (s[front] != s[back] && front < back){
            return false;
        }
        
        else {
            front++;
            back--;
        }
    }
    
    
    return true;
    
    
}



int main(){
    char s[4] = "ab2a";
    bool res = isPalindrome(s);
    if (res)
        printf("True\n");
    
    else
        printf("False\n");

    return 0;
}
