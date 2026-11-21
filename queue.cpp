// Queue (array-based) in C++
// From my Data Structures course - implemented from scratch.
#include <iostream>
using namespace std;

class Queue {
private:
    static const int MAX = 100;
    int arr[MAX];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue() { frontIndex = 0; rearIndex = -1; count = 0; }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAX; }

    // Add a value at the back of the queue
    bool enqueue(int value) {
        if (isFull()) return false;
        rearIndex = (rearIndex + 1) % MAX;
        arr[rearIndex] = value;
        count++;
        return true;
    }

    // Remove the value at the front
    bool dequeue() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % MAX;
        count--;
        return true;
    }

    // Look at the front value without removing it
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[frontIndex];
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front: " << q.front() << endl;  // 1
    q.dequeue();
    cout << "Front after dequeue: " << q.front() << endl;  // 2
    cout << "Is empty? " << (q.isEmpty() ? "yes" : "no") << endl;
    return 0;
}
