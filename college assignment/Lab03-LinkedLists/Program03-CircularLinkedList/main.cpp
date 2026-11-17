/**
 * @file main.cpp
 * @brief Circular Linked List Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>

struct CNode {
    int data;
    CNode* next;
    explicit CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    CNode* tail; // Pointing to tail makes insert at head & tail both O(1)

public:
    CircularLinkedList() : tail(nullptr) {}

    ~CircularLinkedList() {
        if (!tail) return;
        CNode* curr = tail->next;
        tail->next = nullptr; // Break cycle for cleanup
        while (curr) {
            CNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    void insertAtHead(int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtTail(int val) {
        insertAtHead(val);
        tail = tail->next; // Tail advances to newly added node
    }

    void display(int rounds = 1) const {
        if (!tail) {
            std::cout << "List is empty.\n";
            return;
        }
        CNode* head = tail->next;
        CNode* curr = head;
        std::cout << "Circular Traversal (" << rounds << " cycle): ";
        for (int r = 0; r < rounds; ++r) {
            do {
                std::cout << "[" << curr->data << "] -> ";
                curr = curr->next;
            } while (curr != head);
        }
        std::cout << "(back to HEAD: " << head->data << ")\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Circular Linked List\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    CircularLinkedList cll;
    cll.insertAtTail(100);
    cll.insertAtTail(200);
    cll.insertAtTail(300);
    cll.insertAtHead(50);

    cll.display(1);
    std::cout << "\nDemonstrating continuous circular round-robin traversal (2 full cycles):\n";
    cll.display(2);

    return 0;
}
