#include <bits/stdc++.h> 
using namespace std;

class minStack
{
private:
    stack<int> mainstack;
    stack<int> minstack;

public:
    // Constructor
    minStack() 
    {
        // Write your code here if needed.
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        mainstack.push(num);
        if (minstack.empty() || num <= minstack.top())
            minstack.push(num);
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (!mainstack.empty())
        {
            int value = mainstack.top();
            mainstack.pop();
            if (value == minstack.top())
                minstack.pop();
            return value;
        }
        return -1; // Return -1 if the stack is empty.
    }

    // Function to return the top element of the stack if it is present. Otherwise return -1.
    int top()
    {
        if (!mainstack.empty())
            return mainstack.top();
        return -1; // Return -1 if the stack is empty.
    }

    // Function to return the minimum element of the stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (!minstack.empty())
            return minstack.top();
        return -1; // Return -1 if the stack is empty.
    }
};
