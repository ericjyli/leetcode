#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0)  return "";
    if (strsSize == 1)  return strs[0];
    
    int i, j = 0;
    bool same = true;
    if (strsSize>1 &&  strcmp(strs[0],"") == 0){
        return "";
    }
    
    while (same){
        for (i = 0; i < strsSize-1; i++){
            if (strs[i+1][j] != strs[i][j]){
                same = false;
                break;
            }
            else if (strs[i][j] == NULL){
                same = false;
                break;
            }
        }
        if (same)   j++;
        
    }
    
    if (j > 0){
        char *common = (char *) malloc ((j+1)*sizeof (char));
    
        strs[0][j] = '\0';
        strcpy (common,strs[0]);

        return common;
    }
    return "";
}


int main(){
    char *strs[3];
    strs[0] = "flower";
    strs[1] = "flower";
    strs[2] = "flower";
    int strsSize = 3;

    char *result = longestCommonPrefix(strs,strsSize);




    return 0;
}
