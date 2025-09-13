#include <vector>

using namespace std;

int maxFreqSum(string s) {
    vector<int> letterFreq(26, 0);

    for (int i = 0; i < s.length(); ++i) {
        letterFreq[s[i] - 'a'] += 1;
    }

    int vowelFreq = 0;
    int consFreq = 0;

    for (int i = 0; i < 26; ++i) {
        if (i == ('a' - 'a') || i == ('e' - 'a') || i == ('i' - 'a') || i == ('o' - 'a') || i == ('u' - 'a')) {
            vowelFreq = max(vowelFreq, letterFreq[i]);
        }
        else {
            consFreq = max(consFreq, letterFreq[i]);
        }
    }
    return (vowelFreq + consFreq);
}