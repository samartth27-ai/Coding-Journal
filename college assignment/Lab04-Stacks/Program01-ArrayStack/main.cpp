/**
 * @file main.cpp
 * @brief Static Array-based Stack Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <stdexcept>

template <typename T, size_t CAPACITY = 100>
class ArrayStack {
private:
    T data[CAPACITY];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == static_cast<int>(CAPACITY) - 1;
    }

    int size() const {
        return topIndex + 1;
    }

    void push(const T& element) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow: Maximum capacity reached.");
        }
        data[++topIndex] = element;
        std::cout << "[Push] " << element << " (Size: " << size() << ")\n";
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Attempted to pop from an empty stack.");
        }
        T val = data[topIndex--];
        std::cout << "[Pop]  " << val << " (Remaining Size: " << size() << ")\n";
        return val;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty. Cannot peek.");
        }
        return data[topIndex];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack (Top to Bottom): [ ";
        for (int i = topIndex; i >= 0; --i) {
            std::cout << data[i] << " ";
        }
        std::cout << "]\n";
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Array Stack Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    try {
        ArrayStack<int, 5> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.display();

        std::cout << "Top element (peek): " << s.peek() << "\n\n";

        s.pop();
        s.display();

        s.push(40);
        s.push(50);
        s.push(60); // Stack will be full
        s.display();

    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
