#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

    int length() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtPos(int val, int pos) {
        int len = length();
        if (pos < 1 || pos > len + 1) {
            cout << "Invalid position!\n";
            return;
        }
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        if (pos == 1) {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode;
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
        if (len == 1) {
            delete head;
            head = nullptr;
            return;
        }
        if (pos == 1) {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            Node* temp = head;
            head = head->next;
            tail->next = head;
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

    void reverse() {
        if (!head || head->next == head) return;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* tail = head;

        while (tail->next != head) {
            tail = tail->next;
        }

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev;
    }

    void concatenate(CircularLinkedList& list2) {
        if (!head) {
            head = list2.head;
        } else if (list2.head) {
            Node* tail1 = head;
            while (tail1->next != head) {
                tail1 = tail1->next;
            }
            Node* tail2 = list2.head;
            while (tail2->next != list2.head) {
                tail2 = tail2->next;
            }
            tail1->next = list2.head;
            tail2->next = head;
        }
        list2.head = nullptr;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD: " << head->data << ")\n";
    }
};

int main() {
    CircularLinkedList list1, list2;

    cout << "--- Circular Linked List Operations ---\n";
    list1.insertAtPos(5, 1);
    list1.insertAtPos(15, 2);
    list1.insertAtPos(10, 2);
    cout << "List 1 after insertions: ";
    list1.display();

    list1.deleteAtPos(2);
    cout << "List 1 after deleting at pos 2: ";
    list1.display();

    list1.reverse();
    cout << "List 1 after reversing: ";
    list1.display();

    list2.insertAtPos(25, 1);
    list2.insertAtPos(35, 2);
    cout << "List 2: ";
    list2.display();

    list1.concatenate(list2);
    cout << "List 1 after concatenating List 2: ";
    list1.display();

    return 0;
}