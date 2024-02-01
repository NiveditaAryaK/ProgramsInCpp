#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

string concatenate(string str1, string str2) {
    return str1 + str2;
}

int count_alpha(string str) {
    int count = 0;
    for (char c : str) {
        if (isalpha(c)) {
            count++;
        }
    }
    return count;
}

int count_words(string str) {
    int count = 0;
    bool inWord = false;
    for (char c : str) {
        if (isalpha(c)) {
            if (!inWord) {
                count++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}

void printPatternOccurrences(string str) {
    size_t found = str.find("ab");
    while (found != string::npos) {
        cout << "Pattern 'ab' found at index: " << found << endl;
        found = str.find("ab", found + 1);
    }
}

int substringMaxCount(const string& str, string& maxSubstring) {
    int maxCount = 0;
    size_t i = 0;

    while (i < str.length()) {
        size_t found = str.find("ab", i);
        if (found != string::npos) {
            int count = 1;
            i = found + 2;  // Move to the next character after the pattern
            while ((i = str.find("ab", i)) != string::npos) {
                count++;
                i += 2;  // Move to the next character after the pattern
            }

            if (count > maxCount) {
                maxCount = count;
                maxSubstring = str.substr(found, 2);
            }
        } else {
            break;
        }
    }

    return maxCount;
}

bool hasPattern(string str) {
    // Implement pattern recognition logic for "ab"
    size_t found = str.find("ab");
    if (found != string::npos) {
        cout << "Pattern 'ab' found at index: " << found << endl;
        return true;
    }
    return false;
}

int main(void) {
    while (true) {
        cout << "\nChoose Operation: " << endl
             << "1) Concatenation\n2) Number of alphabets\n3) Number of words\n4) Pattern Recognition\n5) Substring Occurrence\n6) Exit\n";
        cout << "Enter option number: ";
        int op;
        cin >> op;

        if (op == 6) {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter string: ";
        string str;
        cin.ignore();  // Ignore the newline character left in the buffer
        getline(cin, str);

        string maxSubstring;
        string str_to_add;

        switch (op) {
        case 1:
            cout << "Enter string to add: ";
            getline(cin, str_to_add);
            cout << "Answer: " << concatenate(str, str_to_add);
            break;
        case 2:
            cout << "Answer: " << count_alpha(str);
            break;
        case 3:
            cout << "Answer: " << count_words(str);
            break;
        case 4:
            if (hasPattern(str)) {
                cout << "Pattern 'ab' exists in the string." << endl;
            } else {
                cout << "Pattern 'ab' does not exist in the string." << endl;
            }
            break;
        case 5:
            cout << "Answer: Maximum occurrence of 'ab' is " << substringMaxCount(str, maxSubstring) << " times, and the substring is: " << maxSubstring;
            break;
        default:
            cerr << "Error! Invalid option." << endl;
            break;
        }
    }

    return 0;
}
