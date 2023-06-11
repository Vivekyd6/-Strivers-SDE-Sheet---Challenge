#include <bits/stdc++.h> 
class Queue {
private:
   int *arr;
   int size;
   int frnt , rear;
public:
    Queue() {
        // Implement the Constructor
        size = 50001;
        arr = new int[size];
        frnt = rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(frnt == rear) return 1;
        else return 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size) return ;
        arr[rear++]= data;
    }

    int dequeue() {
        // Implement the dequeue() functioni

        if(frnt == rear) return -1;
        else {
          int ans = arr[frnt];
          arr[frnt++] = -1;
          if(frnt == rear) frnt = rear = 0;
                    
          return ans;
        }
        
    }

    int front() {
        // Implement the front() function
        if(frnt == rear) return -1;
                return arr[frnt];
    }
};