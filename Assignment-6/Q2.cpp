#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int a[] = {20, 100, 40, 80, 60};
    Node *head = NULL, *last = NULL;

    for (int x : a) {
        Node* n = new Node{x, NULL};

        if (head == NULL)
            head = n;
        else
            last->next = n;

        last = n;
    }

    last->next = head;

    Node* p = head;

    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);

    cout << head->data << endl;

    return 0;
}