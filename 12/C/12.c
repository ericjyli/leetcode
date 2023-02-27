#include <stdlib.h>

/*
Roman numerals are represented by seven different symbols: 
I, V, X, L, C, D and M.
*/


char * intToRoman(int num){
    /*
    I   1
    V   5
    X   10
    L   50
    C   100
    D   500
    M   1000
    */
    
    char* s = (char*) calloc(20,sizeof(char));
    int i = 0;
    
    while (num > 0) {
        if (num >= 1000) {
            s[i++] = 'M';
            num -= 1000;
        } else if (num >= 900) {
            s[i++] = 'C';
            s[i++] = 'M';
            num -= 900;
        } else if (num >= 500) {
            s[i++] = 'D';
            num -= 500;
        } else if (num >= 400) {
            s[i++] = 'C';
            s[i++] = 'D';
            num -= 400;
        } else if (num >= 100) {
            s[i++] = 'C';
            num -= 100;
        }else if (num >= 90) {
            s[i++] = 'X';
            s[i++] = 'C';
            num -= 90;
        } else if (num >= 50) {
            s[i++] = 'L';
            num -= 50;
        } else if (num >= 40) {
            s[i++] = 'X';
            s[i++] = 'L';
            num -= 40;
        } else if (num >= 10) {
            s[i++] = 'X';
            num -= 10;
        } else if (num >= 9) {
            s[i++] = 'I';
            s[i++] = 'X';
            num -= 9;
        } else if (num >= 5) {
            s[i++] = 'V';
            num -= 5;
        } else if (num >= 4){
            s[i++] = 'I';
            s[i++] = 'V';
            num -= 4;
        } else if (num >= 1) {
            s[i++] = 'I';
            num -= 1;
        }
    }
    return s;
}