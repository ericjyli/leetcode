#include <string>
#include <vector>

using namespace std;

vector<string> split_sentence(string sen) {
  
    // Vector to store the words
    vector<string> words;
    
    // Initial index position
    size_t start = 0;
    
    // Variable to store the position of space
    size_t end;
    
    // Loop to find and extract words
    while ((end = sen.find(' ', start)) != string::npos) {
      
        // Extract the word using substr
        words.push_back(sen.substr(start, end - start));
      
        // Update the starting index
        start = end + 1;
    }
    
    // Add the last word to the vector
    words.push_back(sen.substr(start));
    
    return words;
}

bool isCircularSentence(string sentence) {
    vector<string> words = split_sentence(sentence);


    for (int i = 1; i < words.size(); ++i) {
        if (words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
            return false;
        }
    }

    return (words[words.size() - 1][words[words.size() - 1].length() - 1] == words[0][0]);

}
