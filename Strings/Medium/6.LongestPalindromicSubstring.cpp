/*Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 */
//ODD EVEN LOGIC
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;      // starting index of longest palindrome
        int maxlength = 0;  // length of longest palindrome

        for (int i = 0; i < n; i++) {
            // Case 1: Odd length palindrome (center at i)
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxlength) {
                    maxlength = len;
                    start = left;
                }
                left--;
                right++;
            }

            // Case 2: Even length palindrome (center between i and i+1)
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxlength) {
                    maxlength = len;
                    start = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxlength);
    }
};
//NAIVE 
/*class Solution {
public:
    bool isPalindrome(string t) {
        int l = 0, r = t.size() - 1;
        while (l < r) {
            if (t[l] != t[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub)) {
                    if (sub.length() > maxLen) {
                        maxLen = sub.length();
                        ans = sub;
                    }
                }
            }
        }
        return ans;
    }
};*/

int main() {
    string s;
    cin >> s;   // input string

    Solution obj;
    cout << obj.longestPalindrome(s) << endl;

    return 0;
}
