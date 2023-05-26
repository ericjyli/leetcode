#include <string>

using namespace std;

int maxVowels(string s, int k) {
    int length = s.length();
    int p = 0;
    int front = 0;
    int next = k;
    bool front_vowel, next_vowel;
    string first_str = s.substr(0, k);

    int count = 0;
    for (int i = 0; i < first_str.size(); ++i) {
        if (first_str[i] == 'a' || first_str[i] == 'e' 
            || first_str[i] == 'i' || first_str[i] == 'o' || first_str[i] == 'u') {
            count++;
        }
    }
    int max_count = count;



    while (next < length) {
        if (s[front] == 'a' || s[front] == 'e' || s[front] == 'i' || s[front] == 'o' || s[front] == 'u') {
            front_vowel = true;
        }
        else {
            front_vowel = false;
        }
        if (s[next] == 'a' || s[next] == 'e' || s[next] == 'i' || s[next] == 'o' || s[next] == 'u') {
            next_vowel = true;
        }
        else {
            next_vowel = false;
        }   
        if (front_vowel)    count--;
        if (next_vowel)     count++;
        if (count > max_count)  max_count = count;
        front++;
        next++;
    }
    return max_count;
}