#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string kthDistinct(vector<string>& arr, int k) {
    int count = 0;
    unordered_map<string, int> hmap;

    for (int i = 0; i < arr.size(); ++i) {
        if (hmap.find(arr[i]) == hmap.end()) {
            hmap.insert({arr[i], 1});
        }

        else {
            hmap[arr[i]]++;
        }
    }
    
    for (int i = 0; i < arr.size(); ++i) {
        if (hmap[arr[i]] == 1) {
            count++;
            if (count == k) {
                return arr[i];
            }
        }
    }

    return "";

}