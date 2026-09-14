#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++) {

        char ch = exp[i];

        // If operand
        if (isdigit(ch)) {
            s.push(ch - '0');
        }

        // If operator
        else {

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if (ch == '+')
                s.push(a + b);

            else if (ch == '-')
                s.push(a - b);

            else if (ch == '*')
                s.push(a * b);

            else if (ch == '/')
                s.push(a / b);
        }
    }

    cout << "Result: " << s.top();

    return 0;
}