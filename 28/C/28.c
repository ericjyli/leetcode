//leetcode problem 28 C solution

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int strStr(char * haystack, char * needle){

    int i = 0; 
    int length = strlen(needle);
    int l = strlen(haystack);
    char *temp;
    if (length == 0) {
        return 0;
    }
    
    bool end = false;
    
    while (!end){
        if ((l - i) < length){
            return -1;
        }
        if (haystack[i] == needle[0]){
            temp = haystack;
            for (int j = 0; j < i; j++){
                temp++;
            }

            if (strncmp(temp,needle,length) == 0){
                return i;
            }
            else {
                i++;
                continue;
            }
        }
        else {
            i++;
        }
    }
    
    return -1;
}

int main(){
    char *haystack = "hello";
    char *needle = "ll";

    int res = strStr (haystack,needle);

    printf (" %d",res);

    return 0;
}
