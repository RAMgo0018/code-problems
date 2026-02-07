/*The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int count = 0;

        // Fix starting point of substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);  // frequency of characters for current substring

            // Extend substring from i to j
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                // Find max and min frequency in current substring
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                // Add beauty of this substring
                count += (maxi - mini);
            }
        }

        return count;
    }
};

int main() {
    string s;
    cin >> s;   // input string

    Solution obj;
    cout << obj.beautySum(s) << endl;

    return 0;
}
