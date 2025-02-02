#include <vector>

using namespace std;

bool check(vector<int>& nums) {
    bool decreased = false;
    int largest = 0;
    int smallest = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] < nums[i - 1])
        {
            if (decreased)
            {
                return false;
            }
            
            else
            {
                decreased = true;
                largest = nums[i - 1];
            }
        }

        if (decreased && (nums[i] > largest || nums[i] > smallest))
        {
            return false;
        }
    }

    return true;
}