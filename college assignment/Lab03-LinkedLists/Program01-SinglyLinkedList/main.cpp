/**
 * @file main.cpp
 * @brief Singly Linked List Operations (Insert, Delete, Reverse, Search)
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>

struct Node {
    int data;
    Node* next;
    explicit Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to prevent memory leaks
    ~SinglyLinkedList() {
        clear();
    }

    void clear() {
        Node* curr = head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }

    // Insert at beginning - O(1)
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << "[Insert Head] Added " << val << std::endl;
    }

    // Insert at end - O(N)
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        std::cout << "[Insert Tail] Added " << val << std::endl;
    }

    // Insert at 1-based index
    void insertAtPosition(int pos, int val) {
        if (pos <= 1 || !head) {
            insertAtHead(val);
            return;
        }
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != nullptr; ++i) {
            curr = curr->next;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
        std::cout << "[Insert Pos " << pos << "] Added " << val << std::endl;
    }

    // Delete node by value
    bool deleteByValue(int val) {
        if (!head) return false;

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            std::cout << "[Delete] Removed " << val << std::endl;
            return true;
        }

        Node* curr = head;
        while (curr->next != nullptr && curr->next->data != val) {
            curr = curr->next;
        }

        if (curr->next != nullptr) {
            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            std::cout << "[Delete] Removed " << val << std::endl;
            return true;
        }
        std::cout << "[Delete] Value " << val << " not found." << std::endl;
        return false;
    }

    // In-place iterative reversal using 3 pointers - O(N) time, O(1) space
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr != nullptr) {
            nextNode = curr->next; // Store next
            curr->next = prev;     // Reverse pointer
            prev = curr;           // Advance prev
            curr = nextNode;       // Advance curr
        }
        head = prev;
        std::cout << "[Reverse] List reversed in-place successfully." << std::endl;
    }

    // Search for element - O(N)
    bool search(int val) const {
        Node* curr = head;
        int idx = 1;
        while (curr != nullptr) {
            if (curr->data == val) {
                std::cout << "[Search] Found " << val << " at position " << idx << std::endl;
                return true;
            }
            curr = curr->next;
            idx++;
        }
        std::cout << "[Search] Element " << val << " not found." << std::endl;
        return false;
    }

    void display() const {
        if (!head) {
            std::cout << "List is empty.\n";
            return;
        }
        Node* curr = head;
        std::cout << "HEAD -> ";
        while (curr != nullptr) {
            std::cout << "[" << curr->data << "] -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Singly Linked List\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    SinglyLinkedList list;
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtPosition(3, 25);
    list.display();

    list.search(25);
    list.search(99);

    list.deleteByValue(25);
    list.display();

    std::cout << "\nReversing the Linked List:\n";
    list.reverse();
    list.display();

    return 0;
}
