/*Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct item {
        int value;
        int weight;
    };

    static bool cmp(item a, item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;   // descending order of ratio
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<item> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }

        sort(arr.begin(), arr.end(), cmp);

        double totalans = 0.0;

        for (int i = 0; i < n && capacity > 0; i++) {
            if (arr[i].weight <= capacity) {
                totalans += arr[i].value;
                capacity -= arr[i].weight;
            } else {
                totalans += (double)arr[i].value / arr[i].weight * capacity;
                capacity = 0;
            }
        }

        return totalans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> val(n), wt(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];

    int capacity;
    cin >> capacity;

    Solution obj;
    cout << fixed << setprecision(2) << obj.fractionalKnapsack(val, wt, capacity);

    return 0;
}


/*class Solution {
  public:
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        double r1 = (double)a.first / a.second; // value / weight
        double r2 = (double)b.first / b.second;
        return r1 > r2; // descending order
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<int,int>> items;
        
        for(int i = 0; i < n; i++) {
            items.push_back({val[i], wt[i]});
        }
        
        sort(items.begin(), items.end(), cmp);
        
        double totalValue = 0.0;
        
        for(int i = 0; i < n && capacity > 0; i++) {
            int value = items[i].first;
            int weight = items[i].second;
            
            if(weight <= capacity) {
                // take full item
                totalValue += value;
                capacity -= weight;
            } else {
                // take fractional part
                totalValue += ((double)value / weight) * capacity;
                capacity = 0;
            }
        }
        
        return totalValue;
    }
};*/

/*class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double,int>> items;
        
        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }
        
        sort(items.begin(), items.end(), greater<pair<double,int>>());
        
        double totalans = 0.0;
        
        for(int i = 0; i < n && capacity > 0; i++) {
            int index = items[i].second;
            
            if(wt[index] <= capacity) {
                totalans += val[index];
                capacity -= wt[index];
            } else {
                totalans += items[i].first * capacity;
                capacity = 0;
            }
        }
        
        return totalans;
    }
};*/