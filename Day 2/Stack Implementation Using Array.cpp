#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int size=-1;
    int max_size;
public:
    
    Stack(int capacity) {
        // Write your code here.]
        arr = new int[capacity];
       size++;
        max_size = capacity;
    }

    void push(int num) {
        // Write your code here.
      if(size!=max_size) arr[size++]=num;
    }

    int pop() {
        // Write your code here.
        if(size!=0) return arr[--size];
        return -1;
    }
    
    int top() {
        // Write your code here.
        return (size!=0)?arr[size-1]:-1;
    }
    
    int isEmpty() {
        return size==0?1:0;
        // Write your code here.
    }
    
    int isFull() {
        return size==max_size;
        // Write your code here.
    }
    
};