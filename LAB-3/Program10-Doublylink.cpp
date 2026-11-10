
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    int length() {
        int count = 0;
        DNode* temp = head;
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
        DNode* newNode = new DNode(val);
        if (pos == 1) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }
        DNode* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) {
            temp->next->prev = newNode;
        }
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
            DNode* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        DNode* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Reverse links
    void reverse() {
        DNode* temp = nullptr;
        DNode* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Concatenate another list
    void concatenate(DoublyLinkedList& list2) {
        if (!head) {
            head = list2.head;
        } else if (list2.head) {
            DNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = list2.head;
            list2.head->prev = temp;
        }
        list2.head = nullptr;
    }

    // Display
    void display() {
        DNode* temp = head;
        cout << "NULL <-> ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list1, list2;

    cout << "--- Doubly Linked List Operations ---\n";
    list1.insertAtPos(100, 1);
    list1.insertAtPos(300, 2);
    list1.insertAtPos(200, 2); // List 1: 100 <-> 200 <-> 300
    cout << "List 1 after insertions: ";
    list1.display();

    list1.deleteAtPos(2); // Deletes 200
    cout << "List 1 after deleting at pos 2: ";
    list1.display();

    list1.reverse();
    cout << "List 1 after reversing: ";
    list1.display();

    list2.insertAtPos(400, 1);
    list2.insertAtPos(500, 2);
    cout << "List 2: ";
    list2.display();

    list1.concatenate(list2);
    cout << "List 1 after concatenating List 2: ";
    list1.display();

    return 0;
}