/**
 * @file main.cpp
 * @brief Insertion Sort Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>

class InsertionSort {
public:
    static void sort(std::vector<int>& arr, bool verbose = true) {
        int n = static_cast<int>(arr.size());
        int totalShifts = 0;
        int totalComparisons = 0;

        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            if (verbose) {
                std::cout << "Step " << i << " [Inserting Key = " << key << "]: ";
            }

            while (j >= 0) {
                totalComparisons++;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j]; // Shift element rightward
                    totalShifts++;
                    j--;
                } else {
                    break;
                }
            }
            arr[j + 1] = key; // Place key at correct position

            if (verbose) {
                printArray(arr);
            }
        }

        std::cout << "\n[Metrics] Total Comparisons: " << totalComparisons 
                  << " | Total Shifts: " << totalShifts << std::endl;
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
    std::cout << " IC-307D Data Structures LAB - Insertion Sort Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    std::vector<int> arr = {12, 11, 13, 5, 6};
    std::cout << "Initial Array: ";
    InsertionSort::printArray(arr);
    std::cout << "\n--- Execution Trace ---\n";
    InsertionSort::sort(arr);
    std::cout << "\nFinal Sorted Array: ";
    InsertionSort::printArray(arr);

    return 0;
}
