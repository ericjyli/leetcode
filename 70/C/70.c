/*
You are climbing a staircase. 
It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
*/


int climbStairs(int n){
    
    int steps = 0;
    int first = 2;
    int second = 3;
    int temp = 0;
    
    if (n == 1){
        return 1;
    }
    
    if (n == 2){
        return 2;
    }
    
    else {
        while (n > 3){
            n--;
            temp = first + second;
            first = second;
            second = temp;
        }   
    }
    return second;
}
