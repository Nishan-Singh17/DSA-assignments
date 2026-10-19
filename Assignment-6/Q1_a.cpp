//doubly linked list
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

Node* head = NULL;

void insertFirst(int x) {
    Node* n = new Node(x);
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

void insertLast(int x) {
    Node* n = new Node(x);

    if (head == NULL) {
        head = n;
        return;
    }

    Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = n;
    n->prev = p;
}

void insertAfter(int key, int x) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* n = new Node(x);
    n->next = p->next;
    n->prev = p;

    if (p->next != NULL)
        p->next->prev = n;

    p->next = n;
}

void insertBefore(int key, int x) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (p == head) {
        insertFirst(x);
        return;
    }

    Node* n = new Node(x);
    n->prev = p->prev;
    n->next = p;

    p->prev->next = n;
    p->prev = n;
}

void deleteNode(int key) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    delete p;
}

void search(int key) {
    Node* p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    cout << (p ? "Found\n" : "Not found\n");
}

void display() {
    Node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, key;

    do {
        cout << "\n1.Insert First  2.Insert Last";
        cout << "\n3.Insert After  4.Insert Before";
        cout << "\n5.Delete        6.Search";
        cout << "\n7.Display       0.Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cin >> x;
            insertFirst(x);
            break;
        case 2:
            cin >> x;
            insertLast(x);
            break;
        case 3:
            cin >> key >> x;
            insertAfter(key, x);
            break;
        case 4:
            cin >> key >> x;
            insertBefore(key, x);
            break;
        case 5:
            cin >> key;
            deleteNode(key);
            break;
        case 6:
            cin >> key;
            search(key);
            break;
        case 7:
            display();
            break;
        }
    } while (ch != 0);

    return 0;
}