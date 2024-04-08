/*
Given a string s consisting of words and spaces, 
return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.
*/



#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int lengthOfLastWord(char * s){
    int length = 0;
    int totalLength = strlen(s);
    int i = 0;
    
    bool end = false;
    while (i < totalLength){
        if (s[i] != ' '){
           length++;
           i++;
        }
        else if (s[i] == ' '){
            while (s[i] == ' ' && i < (totalLength-1)){
                i++;
            }
            if (i == (totalLength-1) && s[i] == ' '){
                return length;
            }
            else {
                length = 0;
                continue;
            }
        }
        
    }
    return length;
}