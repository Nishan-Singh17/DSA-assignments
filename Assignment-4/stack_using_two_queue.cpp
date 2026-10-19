#include <iostream>
using namespace std;

int q1[100], q2[100];
int f1 = 0, r1 = -1, f2 = 0, r2 = -1;

void push(int x) {
    q2[++r2] = x;

    while (f1 <= r1)
        q2[++r2] = q1[f1++];

    for (int i = f2; i <= r2; i++)
        q1[i - f2] = q2[i];

    r1 = r2 - f2;
    f1 = 0;
    f2 = 0;
    r2 = -1;
}

void pop() {
    if (f1 > r1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << q1[f1++] << "\n";
}

void top() {
    if (f1 > r1)
        cout << "Stack is empty\n";
    else
        cout << "Top: " << q1[f1] << "\n";
}

int main() {
    push(10);
    push(20);
    push(30);

    top();
    pop();
    top();

    return 0;
}