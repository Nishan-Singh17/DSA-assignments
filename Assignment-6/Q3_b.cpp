#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
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
            tail = newNode;
        }
    }

    if (tail != NULL)
        tail->next = head;

    if (head != NULL) {
        Node* p = head;

        do {
            count++;
            p = p->next;
        } while (p != head);
    }

    cout << "Size of CLL = " << count;

    return 0;
}