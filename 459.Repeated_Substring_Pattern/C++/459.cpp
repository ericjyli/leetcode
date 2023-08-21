
#include <string>
using namespace std;


bool repeatedSubstringPattern(string s) {
    int length = s.size();
    for (int i = 1; i < length; ++i) {  // i is the length of the substring pattern
        if (length % i == 0) {
            int num_of_patterns = length / i;
            bool found = true;
            for (int j = 0; j < num_of_patterns; ++j) {
                if (s.substr(j * i, i) != s.substr(0, i)) {
                    found = false;
                    break;
                }
            }
            if (found)  return true;
        }
    }
    return false;
}


