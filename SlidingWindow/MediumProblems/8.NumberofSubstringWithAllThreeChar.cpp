/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> lastseen(3, -1); // to track last seen index of 'a', 'b', 'c'

        for (int i = 0; i < s.length(); i++) {
            lastseen[s[i] - 'a'] = i;

            // check if all three chars have appeared at least once
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                int minLast = min({lastseen[0], lastseen[1], lastseen[2]});
                count += (minLast + 1);
            }
        }

        return count;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.numberOfSubstrings(s);

    return 0;
}
