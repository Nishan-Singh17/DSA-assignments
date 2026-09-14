#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch) {

    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix = postfix + ch;
        }

        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix = postfix + s.top();
                s.pop();
            }

            s.pop();
        }

        // Operator
        else {

            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch)) {

                postfix = postfix + s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix = postfix + s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}