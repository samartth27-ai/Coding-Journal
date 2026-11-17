/**
 * @file main.cpp
 * @brief Binary Search Implementation (Iterative & Recursive) in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>
#include <algorithm>

class BinarySearch {
public:
    // Iterative Binary Search
    static int searchIterative(const std::vector<int>& arr, int target, int& comparisons) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;
        comparisons = 0;

        while (left <= right) {
            comparisons++;
            // Prevent integer overflow: left + (right - left) / 2
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Found
            }
            if (arr[mid] < target) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
        return -1; // Not found
    }

    // Recursive Binary Search
    static int searchRecursive(const std::vector<int>& arr, int left, int right, int target, int& comparisons) {
        if (left > right) {
            return -1;
        }
        comparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            return searchRecursive(arr, mid + 1, right, target, comparisons);
        } else {
            return searchRecursive(arr, left, mid - 1, target, comparisons);
        }
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Binary Search Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    std::vector<int> dataset = {5, 12, 19, 24, 33, 47, 58, 65, 71, 88, 92};
    std::cout << "Sorted Dataset: [ ";
    for (int x : dataset) std::cout << x << " ";
    std::cout << "]\n";

    int target1 = 58;
    int comparisons1 = 0;
    int idx1 = BinarySearch::searchIterative(dataset, target1, comparisons1);
    std::cout << "\nSearch for " << target1 << " (Iterative):\n";
    if (idx1 != -1) {
        std::cout << "  -> Found at index " << idx1 << " in " << comparisons1 << " comparisons.\n";
    } else {
        std::cout << "  -> Target not found.\n";
    }

    int target2 = 50; // Element not present
    int comparisons2 = 0;
    int idx2 = BinarySearch::searchRecursive(dataset, 0, dataset.size() - 1, target2, comparisons2);
    std::cout << "\nSearch for " << target2 << " (Recursive):\n";
    if (idx2 != -1) {
        std::cout << "  -> Found at index " << idx2 << " in " << comparisons2 << " comparisons.\n";
    } else {
        std::cout << "  -> Element not present. Search space exhausted in " 
                  << comparisons2 << " comparisons.\n";
    }

    return 0;
}
