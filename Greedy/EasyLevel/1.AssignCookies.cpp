/*Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

 

Example 1:

Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0; // pointer for cookies
        int r = 0; // pointer for children

        while (l < s.size() && r < g.size()) {
            if (s[l] >= g[r]) {
                r++;   // child satisfied
            }
            l++;       // move to next cookie
        }
        return r;      // number of satisfied children
    }
};

int main() {
    int n, m;
    cin >> n; // number of children
    vector<int> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    cin >> m; // number of cookies
    vector<int> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];

    Solution obj;
    cout << obj.findContentChildren(g, s);

    return 0;
}
