#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct CharNode {
    char data;
    CharNode* next;
    CharNode(char val) : data(val), next(nullptr) {}
};

class CharStack {
private:
    CharNode* top;

public:
    CharStack() : top(nullptr) {}

    void push(char val) {
        CharNode* newNode = new CharNode(val);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!top) return '\0';
        CharNode* temp = top;
        char val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    char peek() {
        if (!top) return '\0';
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    CharStack st;
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop();
        } else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                result += st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        result += st.pop();
    }
    return result;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix = "A+B*C-D/E";
    cout << "Infix Expression: " << infix << "\n";
    cout << "Postfix Expression: " << infixToPostfix(infix) << "\n";
    cout << "Prefix Expression: " << infixToPrefix(infix) << "\n";
    return 0;
}