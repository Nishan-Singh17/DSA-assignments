
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int a[] = {1, 2, 1, 2, 1, 3, 1};
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

    int key = 1, count = 0;

    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* temp = p->next;
            p->next = temp->next;
            delete temp;
            count++;
        } else {
            p = p->next;
        }
    }

    cout << "Count: " << count << "\nUpdated List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";

    return 0;
}
