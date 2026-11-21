// Stack (array-based) in C++
// From my Data Structures course - implemented from scratch.
#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    // Add a value on top of the stack
    bool push(int value) {
        if (isFull()) return false;
        arr[++top] = value;
        return true;
    }

    // Remove the top value
    bool pop() {
        if (isEmpty()) return false;
        top--;
        return true;
    }

    // Look at the top value without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);

    cout << "Top: " << s.peek() << endl;  // 15
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;  // 10
    cout << "Is empty? " << (s.isEmpty() ? "yes" : "no") << endl;
    return 0;
}
