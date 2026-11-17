/**
 * @file main.cpp
 * @brief Selection Sort Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>
#include <utility>

class SelectionSort {
public:
    static void sort(std::vector<int>& arr, bool verbose = true) {
        int n = static_cast<int>(arr.size());
        int totalComparisons = 0;
        int totalSwaps = 0;

        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;

            for (int j = i + 1; j < n; ++j) {
                totalComparisons++;
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }

            // Swap only if a smaller element was found
            if (minIdx != i) {
                std::swap(arr[i], arr[minIdx]);
                totalSwaps++;
            }

            if (verbose) {
                std::cout << "Pass " << (i + 1) << " [Selected Min: " << arr[i] 
                          << " at index " << minIdx << "]: ";
                printArray(arr);
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
    std::cout << " IC-307D Data Structures LAB - Selection Sort Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    std::vector<int> arr = {29, 10, 14, 37, 13};
    std::cout << "Initial Array: ";
    SelectionSort::printArray(arr);
    std::cout << "\n--- Execution Trace ---\n";
    SelectionSort::sort(arr);
    std::cout << "\nFinal Sorted Array: ";
    SelectionSort::printArray(arr);

    return 0;
}
