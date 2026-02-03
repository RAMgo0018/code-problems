/*Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // minimum possible '('
        int high = 0;  // maximum possible '('

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                low++;
                high++;
            }
            else if(s[i] == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat as ')'
                high++;  // treat as '('
            }

            if(low < 0) low = 0;   // we can't have negative open brackets
            if(high < 0) return false; // too many ')'
        }

        return low == 0;
    }
};

int main() {
    string s;
    cin >> s;   // input string

    Solution obj;
    if(obj.checkValidString(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
