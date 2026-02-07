#include <bits/stdc++.h>
using namespace std;

/*
  Function to count substrings with AT LEAST p distinct characters
  using sliding window (two pointers)
*/
long long substringsWithAtLeastPDistinct(string s, int n, int p)
{
    int i, j;
    int c[26];          // frequency array for characters
    int distinct = 0;  // number of distinct characters in window
    long long count = 0;

    // initialize frequency array
    for (i = 0; i < 26; i++)
        c[i] = 0;

    i = 0;
    j = 0;

    for (i = 0; i < n; i++)
    {
        // expand window until we have at least p distinct characters
        while (j < n && distinct < p)
        {
            c[s[j] - 'a']++;
            if (c[s[j] - 'a'] == 1)
                distinct++;   // new character added
            j++;
        }

        // if window has at least p distinct chars
        if (distinct >= p)
        {
            count += n - j + 1;
        }

        // shrink window from left
        c[s[i] - 'a']--;
        if (c[s[i] - 'a'] == 0)
            distinct--;
    }

    return count;
}

/*
  Substrings with EXACTLY k distinct =
  (at least k) - (at least k+1)
*/
long long substringsWithExactlyKDistinct(string s, int k)
{
    int n = s.length();
    return substringsWithAtLeastPDistinct(s, n, k)
         - substringsWithAtLeastPDistinct(s, n, k + 1);
}

int main()
{
    string s;
    int k;

    cin >> s;   // input string
    cin >> k;   // value of k

    cout << substringsWithExactlyKDistinct(s, k);

    return 0;
}
