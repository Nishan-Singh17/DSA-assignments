#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    char stack[100];
    int top = -1;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        stack[++top] = str[i];
    }

    cout << "Reversed string: ";

    while (top != -1) {
        cout << stack[top--];
    }

    return 0;
}