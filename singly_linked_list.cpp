// Singly Linked List in C++
// From my Data Structures course - implemented from scratch.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Add a value at the end of the list
    void insert(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete the first node that holds a value
    bool remove(int value) {
        if (head == nullptr) return false;
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return true;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return false;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return true;
    }

    // Return true if the value exists in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print();              // 10 -> 20 -> 30 -> NULL

    list.remove(20);
    list.print();              // 10 -> 30 -> NULL

    cout << "Search 30: " << (list.search(30) ? "found" : "not found") << endl;
    cout << "Search 99: " << (list.search(99) ? "found" : "not found") << endl;
    return 0;
}
