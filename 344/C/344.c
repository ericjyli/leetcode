/*
Write a function that reverses a string. 
The input string is given as an array of characters s.
*/

void reverseString(char* s, int sSize){

    char temp;
    
    char *front = s;
    char *back = s + sSize -1;
    
    if (front == back){
        return;
    }
    
    else if (sSize == 0){
        return;
    }
    
    else {
        temp = *back;
        *back = *front;
        *front = temp;
        s++;
        reverseString (s,sSize-2);
    }
    
}