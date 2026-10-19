
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int a[] = {1, 2, 3, 4, 5};
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

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow)
        cout << "Middle: " << slow->data;

    return 0;
}
