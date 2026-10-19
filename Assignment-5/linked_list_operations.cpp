
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int x) {
    Node* n = new Node{x, head};
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL};
    if (head == NULL) {
        head = n;
        return;
    }
    Node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = n;
}

void insertBefore(int key, int x) {
    if (head == NULL) return;
    if (head->data == key) {
        insertBeg(x);
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != key)
        p = p->next;
    if (p->next) {
        Node* n = new Node{x, p->next};
        p->next = n;
    } else cout << "Value not found\n";
}

void insertAfter(int key, int x) {
    Node* p = head;
    while (p && p->data != key)
        p = p->next;
    if (p) {
        Node* n = new Node{x, p->next};
        p->next = n;
    } else cout << "Value not found\n";
}

void deleteBeg() {
    if (!head) return;
    Node* p = head;
    head = head->next;
    delete p;
}

void deleteEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node* p = head;
    while (p->next->next)
        p = p->next;
    delete p->next;
    p->next = NULL;
}

void deleteValue(int key) {
    if (!head) return;
    if (head->data == key) {
        deleteBeg();
        return;
    }
    Node* p = head;
    while (p->next && p->next->data != key)
        p = p->next;
    if (p->next) {
        Node* temp = p->next;
        p->next = temp->next;
        delete temp;
    } else cout << "Value not found\n";
}

void search(int key) {
    Node* p = head;
    int pos = 1;
    while (p) {
        if (p->data == key) {
            cout << "Position: " << pos << '\n';
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Value not found\n";
}

void display() {
    Node* p = head;
    while (p) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    int ch, x, key;
    do {
        cout << "\n1.Insert Beginning  2.Insert End"
             << "\n3.Insert Before    4.Insert After"
             << "\n5.Delete Beginning 6.Delete End"
             << "\n7.Delete Value     8.Search"
             << "\n9.Display          0.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cin >> x;
            insertBeg(x);
            break;
        case 2:
            cin >> x;
            insertEnd(x);
            break;
        case 3:
            cin >> key >> x;
            insertBefore(key, x);
            break;
        case 4:
            cin >> key >> x;
            insertAfter(key, x);
            break;
        case 5:
            deleteBeg();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            cin >> key;
            deleteValue(key);
            break;
        case 8:
            cin >> key;
            search(key);
            break;
        case 9:
            display();
            break;
        }
    } while (ch != 0);

    return 0;
}
