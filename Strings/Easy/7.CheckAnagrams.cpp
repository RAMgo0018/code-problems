#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) { 
        int n = s.length();
        int m = t.length();

        // If lengths are different, they cannot be anagrams
        if(n != m) return false;

        unordered_map<char, int> freq;

        // Increase count for s and decrease for t
        for(int i = 0; i < n; i++) {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        // Check if all counts are zero
        for(int i = 0; i < n; i++) {
            if(freq[s[i]] != 0)
                return false;
        }

        return true;
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    Solution obj;

    if(obj.isAnagram(s, t))
        cout << "Anagram";
    else
        cout << "Not Anagram";

    return 0;
}
