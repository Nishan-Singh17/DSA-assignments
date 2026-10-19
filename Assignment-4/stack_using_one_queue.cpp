#include <iostream>
using namespace std;

int q[100], front = 0, rear = -1;

void push(int x) {
    int n = rear - front + 1;
    q[++rear] = x;

    for (int i = 0; i < n; i++)
        q[++rear] = q[front++];

    front = 0;
    rear = n;
}

void pop() {
    if (front > rear) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped: " << q[front++] << "\n";
}

void top() {
    if (front > rear)
        cout << "Stack is empty\n";
    else
        cout << "Top: " << q[front] << "\n";
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