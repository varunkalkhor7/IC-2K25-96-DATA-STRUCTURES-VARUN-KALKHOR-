// ==========================================
// 1. SINGLY LINKED LIST (singly_ll.cpp)
// ==========================================
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Get length of list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Insert at 1-based position
    void insertAtPos(int val, int pos) {
        int len = length();
        if (pos < 1 || pos > len + 1) {
            cout << "Invalid position!\n";
            return;
        }
        Node* newNode = new Node(val);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at 1-based position
    void deleteAtPos(int pos) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        int len = length();
        if (pos < 1 || pos > len) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Reverse list iteratively
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Concatenate another list to the end
    void concatenate(SinglyLinkedList& list2) {
        if (!head) {
            head = list2.head;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = list2.head;
        }
        list2.head = nullptr; // Transfer ownership
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list1, list2;

    cout << "--- Singly Linked List Operations ---\n";
    list1.insertAtPos(10, 1);
    list1.insertAtPos(30, 2);
    list1.insertAtPos(20, 2); // List 1: 10 -> 20 -> 30
    cout << "List 1 after insertions: ";
    list1.display();

    list1.deleteAtPos(2); // Deletes 20
    cout << "List 1 after deleting at pos 2: ";
    list1.display();

    list1.reverse();
    cout << "List 1 after reversing: ";
    list1.display();

    list2.insertAtPos(40, 1);
    list2.insertAtPos(50, 2);
    cout << "List 2: ";
    list2.display();

    list1.concatenate(list2);
    cout << "List 1 after concatenating List 2: ";
    list1.display();

    return 0;
}