#include <iostream>
using namespace std;

int q[100], temp[100];
int front = 0, rear = -1;
int tf = 0, tr = -1;

int main() {
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q[++rear] = x;
    }

    for (int i = 0; i < n / 2; i++)
        temp[++tr] = q[front++];

    while (tf <= tr) {
        q[++rear] = temp[tf++];
        q[++rear] = q[front++];
    }

    for (int i = 0; i < n; i++)
        cout << q[front++] << " ";

    return 0;
}