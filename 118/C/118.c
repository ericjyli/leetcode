
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
Given an integer numRows, 
return the first numRows of Pascal's triangle.
*/



#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    *returnSize = numRows;
    int **res = malloc (numRows *sizeof(int*));
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    
    for (int i = 0; i < numRows; i++){
        res[i] = malloc ((i+1)*sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j < (i+1); j++){
            if (j == 0 || j == i){
                res[i][j] = 1;
            }
            
            else {
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
            
        }
    }
    return res;
    
}