/*Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;   // current depth
        int res = 0;     // maximum depth

        for (char it : s) {
            if (it == '(')
                count++;        // opening bracket increases depth
            else if (it == ')')
                count--;        // closing bracket decreases depth

            res = max(res, count); // update maximum depth
        }

        return res;
    }
};

int main() {
    string s;
    cin >> s;   // input string

    Solution obj;
    cout << obj.maxDepth(s) << endl;

    return 0;
}
