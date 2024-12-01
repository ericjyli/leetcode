#include <vector>
#include <map>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> mmap;

    for (int i = 0; i < arr.size(); ++i) {
        if (mmap.find(arr[i] * 2) != mmap.end() || (mmap.find(arr[i]/2) != mmap.end() && arr[i] % 2 == 0)) {
            return true;
        }
        mmap.insert({arr[i], i});
    }

    return false;
}
