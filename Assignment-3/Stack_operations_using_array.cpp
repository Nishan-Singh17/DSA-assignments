#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow\n";
        }
        else {
            top++;
            arr[top] = x;
            cout << "Element pushed\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        }
        else {
            cout << "Popped element: " << arr[top] << endl;
            top--;
        }
    }

    void isEmpty() {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Stack is not Empty\n";
    }

    void isFull() {
        if (top == 99)
            cout << "Stack is Full\n";
        else
            cout << "Stack is not Full\n";
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
        }
        else {
            cout << "Stack elements: ";

            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";

            cout << endl;
        }
    }

    void peek() {
        if (top == -1)
            cout << "Stack is Empty\n";
        else
            cout << "Top element: " << arr[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. isEmpty";
        cout << "\n4. isFull";
        cout << "\n5. Display";
        cout << "\n6. Peek";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.isEmpty();
                break;

            case 4:
                s.isFull();
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.peek();
                break;

            case 7:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}