/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) return false;

                char chk = stk.top();
                stk.pop();

                if (!((chk == '(' && s[i] == ')') ||
                      (chk == '{' && s[i] == '}') ||
                      (chk == '[' && s[i] == ']')))
                    return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution sol;

    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "{[()]}";

    cout << s1 << " -> " << (sol.isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (sol.isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (sol.isValid(s3) ? "Valid" : "Invalid") << endl;

    return 0;
}
