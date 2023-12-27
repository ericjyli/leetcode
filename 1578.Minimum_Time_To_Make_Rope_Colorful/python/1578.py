from typing import List

def minCost(colors: str, neededTime: List[int]) -> int:
    dp = [0] * len(colors)
    curr = -1
    # curr is the index of the largest neededTime of the current color
    for i in range (1, len(colors)):
        if colors[i] == colors[i - 1]:
            if curr != - 1 and colors[curr] == colors[i]:
                dp[i] = dp[i - 1] + min(neededTime[i], neededTime[curr])
                if neededTime[i] > neededTime[curr]:
                    curr = i
            
            else:
                if neededTime[i] < neededTime[i - 1]:
                    curr = i - 1
                else:
                    curr = i
                dp[i] = dp[i - 1] + min(neededTime[i], neededTime[i - 1])
            
        else:
            dp[i] = dp[i - 1]
            curr = -1
        # print(f'dp[{i}]: {dp[i]}')
    
    return dp[len(colors) - 1]


if __name__ == '__main__':
    colors1 = "aaabbbabbbb"
    neededTime1 = [3,5,10,7,5,3,5,5,4,8,1]
    res1 = minCost(colors1, neededTime1)
    print(res1)
    
    colors2 = "aaaaaaaaaaaaaa"
    neededTime2 = [1,3,6,5,4,5,4,4,2,8,3,10,6,6]
    res2 = minCost(colors2, neededTime2)
    print(res2)