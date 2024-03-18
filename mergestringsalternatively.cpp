#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string result;
    int i = 0, j = 0;

    // Loop until either word1 or word2 is fully processed
    while (i < word1.length() && j < word2.length()) {
        // Append characters from word1 and word2 alternately
        result.push_back(word1[i++]);
        result.push_back(word2[j++]);
    }

    // Append remaining characters from word1, if any
    while (i < word1.length()) {
        result.push_back(word1[i++]);
    }

    // Append remaining characters from word2, if any
    while (j < word2.length()) {
        result.push_back(word2[j++]);
    }

    return result;
}

int main() {
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;

    string merged = mergeAlternately(word1, word2);
    cout << "Merged string: " << merged << endl;

    return 0;
}
