/**
 * @file main.cpp
 * @brief Merge Sort Implementation in C++
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>

class MergeSort {
private:
    static void merge(std::vector<int>& arr, int left, int mid, int right, int& mergeCount) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<int> L(n1);
        std::vector<int> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) { // '<=' preserves stability
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        mergeCount++;
    }

    static void sortInternal(std::vector<int>& arr, int left, int right, int& mergeCount) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Prevents overflow

            // Divide
            sortInternal(arr, left, mid, mergeCount);
            sortInternal(arr, mid + 1, right, mergeCount);

            // Conquer / Combine
            merge(arr, left, mid, right, mergeCount);
        }
    }

public:
    static void sort(std::vector<int>& arr) {
        int mergeCount = 0;
        if (!arr.empty()) {
            sortInternal(arr, 0, static_cast<int>(arr.size()) - 1, mergeCount);
        }
        std::cout << "[Metrics] Total Subarray Merges: " << mergeCount << std::endl;
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
    std::cout << " IC-307D Data Structures LAB - Merge Sort Program\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n\n";

    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Initial Array: ";
    MergeSort::printArray(arr);

    std::cout << "\nExecuting Divide-and-Conquer Merge Sort...\n";
    MergeSort::sort(arr);

    std::cout << "Sorted Array:  ";
    MergeSort::printArray(arr);

    return 0;
}
