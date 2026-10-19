#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;

    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

int main() {
    Node *head = NULL, *tail = NULL;
    int n, x, count = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node(x);

        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* p = head;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    cout << "Size of DLL = " << count;

    return 0;
}