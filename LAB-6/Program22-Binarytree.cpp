#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void recursiveInorder(Node* root) {
    if (!root) return;
    recursiveInorder(root->left);
    cout << root->data << " ";
    recursiveInorder(root->right);
}

void recursivePreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void recursivePostorder(Node* root) {
    if (!root) return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->data << " ";
}

void iterativeInorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void iterativePreorder(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void iterativePostorder(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Recursive Inorder: ";
    recursiveInorder(root);
    cout << "\nIterative Inorder: ";
    iterativeInorder(root);

    cout << "\n\nRecursive Preorder: ";
    recursivePreorder(root);
    cout << "\nIterative Preorder: ";
    iterativePreorder(root);

    cout << "\n\nRecursive Postorder: ";
    recursivePostorder(root);
    cout << "\nIterative Postorder: ";
    iterativePostorder(root);
    cout << "\n";

    return 0;
}