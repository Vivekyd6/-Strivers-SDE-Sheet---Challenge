#include <bits/stdc++.h> 
class Stack {
	// Defi;ne the data members.

    private:
    queue<int>q1;
    queue<int>q2;
    int n;

   public:
    Stack() {
        // Implement the Constructor.
        n = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return n;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return n==0;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        n++;
    }

    int pop() {
        // Implement the pop() function.
        if(!q1.empty()){
            int value = q1.front();
            q1.pop();
            n--;
            return value;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q1.empty()){
            return q1.front();
        }
        return -1;
    }
};