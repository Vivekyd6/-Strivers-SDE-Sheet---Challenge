#include <bits/stdc++.h> 

void sortedStack(stack<int> &stack, int num){
    //base case
    if(stack.empty() || stack.top() < num){ 
        stack.push(num);
        return ;
    }
    int n = stack.top();
    stack.pop();
    //Recursive call
    sortedStack(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedStack(stack,num);
}