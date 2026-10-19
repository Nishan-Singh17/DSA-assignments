//circular linked list
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

Node* head = NULL;

void insertFirst(int x) {
    Node* n = new Node(x);

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* p = head;
    while (p->next != head)
        p = p->next;

    n->next = head;
    p->next = n;
    head = n;
}

void insertLast(int x) {
    Node* n = new Node(x);

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node* p = head;
    while (p->next != head)
        p = p->next;

    p->next = n;
    n->next = head;
}

void insertAfter(int key, int x) {
    if (head == NULL) {
        cout << "Node not found\n";
        return;
    }

    Node* p = head;

    do {
        if (p->data == key) {
            Node* n = new Node(x);
            n->next = p->next;
            p->next = n;
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "Node not found\n";
}

void insertBefore(int key, int x) {
    if (head == NULL) {
        cout << "Node not found\n";
        return;
    }

    if (head->data == key) {
        insertFirst(x);
        return;
    }

    Node* p = head;

    while (p->next != head && p->next->data != key)
        p = p->next;

    if (p->next == head) {
        cout << "Node not found\n";
        return;
    }

    Node* n = new Node(x);
    n->next = p->next;
    p->next = n;
}

void deleteNode(int key) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node *p = head, *prev = NULL;

    do {
        if (p->data == key) {
            if (p->next == p) {
                head = NULL;
            } else {
                if (prev == NULL) {
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = p->next;
                }
            }

            delete p;
            return;
        }

        prev = p;
        p = p->next;
    } while (p != head);

    cout << "Node not found\n";
}

void search(int key) {
    if (head == NULL) {
        cout << "Not found\n";
        return;
    }

    Node* p = head;

    do {
        if (p->data == key) {
            cout << "Found\n";
            return;
        }
        p = p->next;
    } while (p != head);

    cout << "Not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* p = head;

    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);

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