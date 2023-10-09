#include <vector>

using namespace std;




vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size()-1;
    while (l < r) {
        int s = numbers[l]+numbers[r];
        if (s > target) 
            r--;
        else if (s < target)
            l++;
        else 
            return {l+1, r+1};
    }
    return {};
}