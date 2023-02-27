/*
You are given an array prices 
where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit 
by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
*/


int maxProfit(int* prices, int pricesSize){
    int lowIndex = 0;
    
    int i = 1;
    int profit = 0;
    int temp;
    while (i < pricesSize){
        temp = prices[i] - prices[lowIndex];
        if (temp <= 0){
            lowIndex = i;
        }
        
        else if (temp > 0){
            if (temp > profit){
                profit = temp;
            }
        }
        i++;
    }
    
    return profit;
}