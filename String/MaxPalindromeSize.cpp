
#include <iostream>
#include <string>
using namespace std;

int LongestPalindrome(string &s) {
    int lowersum = 0, uppersum = 0, oddeven = 0;
    int LowerCase[26], UpperCase[26];

    for (int i = 0; i < 26; i++) {
        LowerCase[i] = 0;
        UpperCase[i] = 0;
    }

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            LowerCase[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            UpperCase[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (LowerCase[i] % 2 == 0) {
            lowersum += LowerCase[i];
        } else {
            LowerCase[i]--;
            lowersum += LowerCase[i];
            oddeven++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (UpperCase[i] % 2 == 0) {
            uppersum += UpperCase[i];
        } else {
            uppersum += (UpperCase[i] - 1);
            oddeven++;
        }
    }

    int result = oddeven > 0 ? (uppersum + lowersum + 1) : (uppersum + lowersum);
    return result;
}

int main() {
    string s;
    cout << "Enter the word : ";
    getline(cin, s);
    int size = LongestPalindrome(s);
    cout << "The max palindrome is form of size: " << size;
    return 0;
}
