#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

*/

bool isMatch(char * s, char * p){
    int i=0;
    int j=0;
    bool end = false;
    while (!end){
        if (i == strlen(s) || i > strlen(s)){
            break;
        }
        
        if (s[i] == p[j]){
            i++;
            j++;
            continue;
        }
        
        //when s[i] != p[j]
        
        if (p[j] == '.'){   //any element
            p[j] = s[i];
        }
        
        if (p[j] == '*'){   //zero or more of the preceding element
            p[j] = p[j-1];  
            while ((i+1) < strlen(s) && s[i+1] == s[i]){
                i++;
            }
        }
        
        if (s[i] != p[j]){
            return false;
        }
        
    }
    
    return true;
}
