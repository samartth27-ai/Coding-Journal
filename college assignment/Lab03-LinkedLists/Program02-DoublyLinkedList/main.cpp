/**
 * @file main.cpp
 * @brief Doubly Linked List with Bidirectional Traversal in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    explicit DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        DNode* curr = head;
        while (curr) {
            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void insertAtHead(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val) {
        DNode* newNode = new DNode(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool deleteNode(int val) {
        DNode* curr = head;
        while (curr && curr->data != val) {
            curr = curr->next;
        }
        if (!curr) return false;

        if (curr == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (curr == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        delete curr;
        return true;
    }

    void displayForward() const {
        std::cout << "Forward : NULL <-> ";
        DNode* curr = head;
        while (curr) {
            std::cout << "[" << curr->data << "] <-> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    void displayBackward() const {
        std::cout << "Backward: NULL <-> ";
        DNode* curr = tail;
        while (curr) {
            std::cout << "[" << curr->data << "] <-> ";
            curr = curr->prev;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Doubly Linked List\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    DoublyLinkedList dll;
    dll.insertAtHead(20);
    dll.insertAtHead(10);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    std::cout << "After Insertions:\n";
    dll.displayForward();
    dll.displayBackward();

    std::cout << "\nDeleting node with value 30...\n";
    dll.deleteNode(30);
    dll.displayForward();
    dll.displayBackward();

    return 0;
}
