#include <string>
#include <vector>

using namespace std;

int countSeniors(vector<string>& details) {
    
    int res = 0;
    for (int i = 0; i < details.size(); ++i) {
        if (atoi(details[i].substr(11, 2).c_str()) > 60)
            res++;
    }

    return res;
}