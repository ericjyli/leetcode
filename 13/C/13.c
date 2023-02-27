#include <string.h>


int romanToInt(char * s){

    /*
    I   1
    V   5
    X   10
    L   50
    C   100
    D   500
    M   1000
    */

    int res = 0;
    int size = strlen(s);
    int i = 0;
    while (i < size){
        if (s[i] == 'I'){
            
            //I can be placed before V (5) and X (10) to make 4 and 9. 
            if (s[i+1] == 'V'){
                res += 4;
                i++;
            }
            
            else if (s[i+1] == 'X'){
                res += 9;
                i++;
            }
            
            else {
                res += 1;
            }
        }
        
        else if (s[i] == 'V')
            res += 5;
        
        else if (s[i] == 'X'){
            //X can be placed before L (50) and C (100) to make 40 and 90.
            if (s[i+1] == 'L'){
                res += 40;
                i++;
            }
            
            else if (s[i+1] == 'C'){
                res += 90;
                i++;
            }
            
            else {
                res += 10;
            }
        }
        
        else if (s[i] == 'L')
            res += 50;
        
        else if (s[i] == 'C'){
            //C can be placed before D (500) and M(1000) to make 400 and 900
            if (s[i+1] == 'D'){
                res += 400;
                i++;
            }
            
            else if (s[i+1] == 'M'){
                res += 900;
                i++;
            }
            
            else {
                res += 100;
            }
        }
        else if (s[i] == 'D')
            res += 500;
        else if (s[i] == 'M')
            res += 1000;
        
        i++;
    }
        

    
    return res;
}