
#include <queue>

using namespace std;


// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, 
// which means that only push to back, peek/pop from front, size and is empty operations are valid.

class MyStack {
    queue<int> q1;
public:
    MyStack() {
    
    }
    
    void push(int x) {
        q1.push(x);
        for (int i = 1; i < q1.size(); i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int num = q1.front();
        q1.pop();    
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */