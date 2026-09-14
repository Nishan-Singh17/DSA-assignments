#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    stack<char> s;

    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {

            if (s.empty()) {
                cout << "Not Balanced";
                return 0;
            }

            char x = s.top();
            s.pop();

            if ((exp[i] == ')' && x != '(') ||
                (exp[i] == ']' && x != '[') ||
                (exp[i] == '}' && x != '{')) {

                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (s.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}