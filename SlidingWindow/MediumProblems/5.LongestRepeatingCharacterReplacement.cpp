/*You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0;
        int l = 0;
        int maxlength = 0;
        vector<int> hash(26, 0);
        int maxfreq = 0;

        while (r < s.length())
        {
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r] - 'A']);

            while ((r - l + 1) - maxfreq > k)
            {
                hash[s[l] - 'A']--;
                maxfreq = 0;
                for (int i = 0; i < hash.size(); i++)
                {
                    maxfreq = max(maxfreq, hash[i]);
                }
                l++;
            }

            if ((r - l + 1) - maxfreq <= k)
            {
                maxlength = max(maxlength, r - l + 1);
                r++;
            }
        }
        return maxlength;
    }
};

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    Solution obj;
    cout << obj.characterReplacement(s, k);

    return 0;
}
