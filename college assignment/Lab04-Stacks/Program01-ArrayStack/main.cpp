/**
 * @file main.cpp
 * @brief Static Array-based Stack Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */


#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Insert element
    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            arr[top] = x;
            cout << x << " pushed into stack" << endl;
        }
    }

    // Remove element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << arr[top] << " popped from stack" << endl;
            top--;
        }
    }

    // Display top element
    void peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
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
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}

