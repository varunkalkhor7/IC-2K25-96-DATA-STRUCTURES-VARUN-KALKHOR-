#include <iostream>
#include <string>
using namespace std;

struct IntNode {
    int data;
    IntNode* next;
    IntNode(int val) : data(val), next(nullptr) {}
};

class IntStack {
private:
    IntNode* top;

public:
    IntStack() : top(nullptr) {}

    void push(int val) {
        IntNode* newNode = new IntNode(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!top) return 0;
        IntNode* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int evaluatePostfix(string exp) {
    IntStack st;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int val1 = st.pop();
            int val2 = st.pop();
            switch (c) {
                case '+': st.push(val2 + val1); break;
                case '-': st.push(val2 - val1); break;
                case '*': st.push(val2 * val1); break;
                case '/': st.push(val2 / val1); break;
            }
        }
    }
    return st.pop();
}

int main() {
    string postfix = "231*+9-";
    cout << "Postfix Expression: " << postfix << "\n";
    cout << "Evaluated Result: " << evaluatePostfix(postfix) << "\n";
    return 0;
}