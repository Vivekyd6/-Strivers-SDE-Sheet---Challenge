#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &prices) {
    // Write your code here.
    // stack<pair<int, int>> s; 
    // vector<int> ans(price.size());

    // for (int i = 0; i < price.size(); i++) {  
    //       int span = 1;    
    //       while (s.size() and s.top().first <= price[i]) {  
    //               span += s.top().second;    
    //                 s.pop();
    //          }   
    //      s.push({price[i], span});  
    //     ans[i] = span;  
    //     }
    //  return ans;
    int n = prices.size();
    vector<int> spans(n, 0);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while the stack is not empty
        // and the current price is greater than the price at the index at the top of the stack
        while (!stack.empty() && prices[i] >= prices[stack.top()]) {
            stack.pop();
        }

        // Calculate the span for the current day
        if (stack.empty()) {
            spans[i] = i + 1;
        } else {
            spans[i] = i - stack.top();
        }

        // Push the current index onto the stack
        stack.push(i);
    }

    return spans;
}