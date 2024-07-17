#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap;
    int maxLength = 0, start = 0;
    for (int end = 0; end < s.size(); ++end) {
        if (charMap.find(s[end]) != charMap.end()) {
            start = max(charMap[s[end]] + 1, start);
        }
        charMap[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}

