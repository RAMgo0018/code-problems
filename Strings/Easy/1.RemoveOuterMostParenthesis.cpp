/*A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(st.empty())
                    st.push('(');
                else {
                    st.push('(');
                    ans += s[i];
                }
            }
            else if(s[i] == ')') {
                st.pop();
                if(!st.empty()) {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

int main() {
    string s;
    cin >> s;   // input string

    Solution obj;
    cout << obj.removeOuterParentheses(s);

    return 0;
}
/*OPTIMAL SOLUTION USING COUNT AS REFERENCE
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count=0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(count>0)
                ans+=s[i];
                count++;
            }
            else if(s[i] == ')')
            {
                count--;
                if(count>0)
                ans+=s[i];
        
            }
        }
        return ans;
    }
};*/