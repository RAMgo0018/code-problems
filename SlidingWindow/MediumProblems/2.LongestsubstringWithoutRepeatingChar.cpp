/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int l = 0;
        int r = 0;
        vector<int> lastseen(128, -1);

        while (r < s.size()) {
            if (lastseen[s[r]] >= l) {
                l = lastseen[s[r]] + 1;
            }
            maxlength = max(maxlength, r - l + 1);
            lastseen[s[r]] = r;
            r++;
        }
        return maxlength;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.lengthOfLongestSubstring(s);

    return 0;
}
