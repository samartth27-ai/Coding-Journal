/**
 * @file main.cpp
 * @brief Optimized Bubble Sort Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>
#include <utility>

class BubbleSort {
public:
    // Performs bubble sort with early-exit optimization
    static void sort(std::vector<int>& arr, bool verbose = true) {
        int n = static_cast<int>(arr.size());
        int totalComparisons = 0;
        int totalSwaps = 0;

        for (int i = 0; i < n - 1; ++i) {
            bool swapped = false;
            if (verbose) {
                std::cout << "--- Pass " << (i + 1) << " ---" << std::endl;
            }

            for (int j = 0; j < n - i - 1; ++j) {
                totalComparisons++;
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                    totalSwaps++;
                }
            }

            if (verbose) {
                printArray(arr);
            }

            // Optimization: If no two elements were swapped in inner loop, array is sorted
            if (!swapped) {
                if (verbose) {
                    std::cout << "Early exit triggered at Pass " << (i + 1) << " (Array is already sorted)." << std::endl;
                }
                break;
            }
        }

        std::cout << "\n[Metrics] Total Comparisons: " << totalComparisons 
                  << " | Total Swaps: " << totalSwaps << std::endl;
    }

    static void printArray(const std::vector<int>& arr) {
        std::cout << "[ ";
        for (int val : arr) {
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Bubble Sort Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    // Test Case 1: Unsorted array
    std::vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Test Case 1: Unsorted Array\nInitial: ";
    BubbleSort::printArray(arr1);
    BubbleSort::sort(arr1);
    std::cout << "Sorted Result: ";
    BubbleSort::printArray(arr1);

    std::cout << "\n--------------------------------------------------------\n";

    // Test Case 2: Best-case already sorted array (demonstrates O(n) early exit)
    std::vector<int> arr2 = {10, 20, 30, 40, 50};
    std::cout << "\nTest Case 2: Best-Case Already Sorted Array (Early Exit)\nInitial: ";
    BubbleSort::printArray(arr2);
    BubbleSort::sort(arr2);
    std::cout << "Sorted Result: ";
    BubbleSort::printArray(arr2);

    return 0;
}
