#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;

    Node(char c) {
        data = c;
        prev = next = NULL;
    }
};

int main() {
    string s;
    cin >> s;

    Node *head = NULL, *tail = NULL;

    for (char c : s) {
        Node* n = new Node(c);

        if (head == NULL)
            head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    bool palindrome = true;

    Node *left = head, *right = tail;

    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            palindrome = false;
            break;
        }

        left = left->next;
        right = right->prev;
    }

    cout << (palindrome ? "True" : "False");

    return 0;
}