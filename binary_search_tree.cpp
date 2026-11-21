// Binary Search Tree in C++
// From my Data Structures course - implemented from scratch.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node{value, nullptr, nullptr};
        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        return node;
    }

    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    // Inorder traversal prints values sorted from smallest to largest
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() { root = nullptr; }
    void insert(int value) { root = insert(root, value); }
    bool search(int value) { return search(root, value); }
    void printInorder() { inorder(root); cout << endl; }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    tree.printInorder();  // 20 30 40 50 70
    cout << "Search 40: " << (tree.search(40) ? "found" : "not found") << endl;
    cout << "Search 99: " << (tree.search(99) ? "found" : "not found") << endl;
    return 0;
}
