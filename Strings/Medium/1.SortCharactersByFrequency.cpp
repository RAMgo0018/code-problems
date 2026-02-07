/*Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        // Frequency array for all ASCII characters
        vector<int> freq(256, 0);

        // Count frequency of each character
        for (char c : s)
            freq[(unsigned char)c]++;

        // Custom comparator for sorting
        auto cmp = [&](char a, char b) {
            // If frequencies are equal, sort by character (optional tie-breaker)
            if (freq[(unsigned char)a] == freq[(unsigned char)b])
                return a > b;
            // Otherwise, sort by decreasing frequency
            return freq[(unsigned char)a] > freq[(unsigned char)b];
        };

        // Sort the string using custom comparator
        sort(s.begin(), s.end(), cmp);

        return s;
    }
};
/*class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for(char ch : s)
            freq[ch]++;

        vector<pair<char,int>> freqArr;
        for(auto it : freq)
            freqArr.push_back({it.first, it.second});

        auto cmp = [](pair<char,int> a, pair<char,int> b) {
            return a.second > b.second;
        };

        sort(freqArr.begin(), freqArr.end(), cmp);

        string result = "";
        for(auto it : freqArr) {
            result += string(it.second, it.first);
        }

        return result;
    }
};*/

int main() {
    string s;
    cin >> s;

    Solution obj;
    string result = obj.frequencySort(s);

    cout << result << endl;

    return 0;
}
