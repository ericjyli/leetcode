#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.


struct Fractions {
    int num;
    int denom;
    double frac;
};

bool compareFractions(const Fractions& a, const Fractions& b) {
    return a.frac < b.frac;
}

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    // dumb O(n^2) solution

    vector<Fractions> fractions;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            fractions.push_back({arr[i], arr[j], (double)arr[i] / arr[j]});
        }
    }
    sort(fractions.begin(), fractions.end(), compareFractions);

    vector<int> res;
    res.push_back(fractions[k - 1].num);
    res.push_back(fractions[k - 1].denom);

    return res;


}
