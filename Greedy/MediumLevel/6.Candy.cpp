/*
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n);
        vector<int> right(n);
        int sum=0;
        
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                left[i]=left[i-1]+1;
            }
            else
            {
                left[i]=1;
            }
        }
        for(int j=n-2;j>=0;j--)
        {
            if(ratings[j]>ratings[j+1])
            {
                right[j]=right[j+1]+1;
            }
            else
            {
                right[j]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=max(left[i],right[i]);
        }
        return sum;
        
    }
};
*/
/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        int sum = 0;

        // Left to right pass
        left[0] = 1;
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        }

        int curr = 1;          // current right-side candies
        int rightelement = 1; // previous right-side value

        sum = max(1, left[n-1]);

        // Right to left pass
        for(int j = n-2; j >= 0; j--) {
            if(ratings[j] > ratings[j+1]) {
                curr = rightelement + 1;
                rightelement = curr;
            } else {
                curr = 1;
                rightelement = 1;
            }

            sum += max(curr, left[j]);
        }

        return sum;
    }
};

int main() {
    int n;
    cin >> n;   // number of children

    vector<int> ratings(n);
    for(int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    Solution obj;
    cout << obj.candy(ratings) << endl;

    return 0;
}
