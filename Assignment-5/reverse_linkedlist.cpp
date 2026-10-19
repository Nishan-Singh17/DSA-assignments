
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int a[] = {1, 2, 3, 4};
    Node* head = NULL;
    Node* tail = NULL;

    for (int x : a) {
        Node* n = new Node{x, NULL};
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    Node* prev = NULL;
    Node* curr = head;

    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";

    return 0;
}
