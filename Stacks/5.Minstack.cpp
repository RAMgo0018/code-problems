/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini = LLONG_MAX;

public:
    MinStack() {}

    void push(long long val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else if (val > mini) {
            st.push(val);
        } else {
            st.push(2 * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    long long top() {
        if (st.empty()) return -1;

        if (st.top() < mini)
            return mini;
        else
            return st.top();
    }

    long long getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};

int main() {
    MinStack st;

    st.push(5);
    cout << "Min: " << st.getMin() << endl;   // 5

    st.push(3);
    cout << "Min: " << st.getMin() << endl;   // 3

    st.push(7);
    cout << "Top: " << st.top() << endl;      // 7
    cout << "Min: " << st.getMin() << endl;   // 3

    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 3
    cout << "Min after pop: " << st.getMin() << endl; // 3

    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 5
    cout << "Min after pop: " << st.getMin() << endl; // 5

    return 0;
}
