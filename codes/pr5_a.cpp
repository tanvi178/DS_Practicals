//Parenthesis Checker
#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    char arr[MAX];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == MAX - 1;
    }
    
    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }
    
    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
    
    char peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return '\0';
    }
};

bool isBalanced(string expr) {
    Stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;
    
    if (isBalanced(expression)) {
        cout << "Balanced Expression " << endl;
    } else {
        cout << "Not Balanced " << endl;
    }
    
    return 0;
}
