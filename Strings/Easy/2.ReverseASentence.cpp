/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;

        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] != ' ') {
                st.push(s[i]);
            } else {
                if(!st.empty()) {   // process a word only if stack has chars
                    while(!st.empty()) {
                        ans += st.top();
                        st.pop();
                    }
                    ans += ' ';
                }
            }
        }

        // add the last word
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // remove trailing space if present
        if(!ans.empty() && ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};

int main() {
    string s;
    getline(cin, s);   // take full line with spaces

    Solution obj;
    cout << obj.reverseWords(s);

    return 0;
}
