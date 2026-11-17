/**
 * @file main.cpp
 * @brief Student Record Management System with Sorting & Searching
 * @course IC-307D: Data Structures & Algorithms LAB
 * @author Samarth Dubey (Roll No: IC-2K25-75)
 * @institution IIPS, Devi Ahilya Vishwavidyalaya (DAVV), Indore
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Student {
    int rollNo;
    std::string name;
    double marks;

    void display() const {
        std::cout << "| " << std::setw(8) << rollNo 
                  << " | " << std::setw(20) << std::left << name 
                  << " | " << std::setw(8) << std::right << std::fixed << std::setprecision(1) << marks 
                  << " |" << std::endl;
    }
};

class StudentRecordManager {
private:
    std::vector<Student> students;

    // Merge helper for Merge Sort by Roll Number
    static void mergeByRoll(std::vector<Student>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<Student> L(n1);
        std::vector<Student> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].rollNo <= R[j].rollNo) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    static void mergeSortRoll(std::vector<Student>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortRoll(arr, left, mid);
            mergeSortRoll(arr, mid + 1, right);
            mergeByRoll(arr, left, mid, right);
        }
    }

public:
    void addStudent(int roll, const std::string& name, double marks) {
        students.push_back({roll, name, marks});
    }

    void displayTable(const std::string& title) const {
        std::cout << "\n=======================================================\n";
        std::cout << " " << title << "\n";
        std::cout << "=======================================================\n";
        std::cout << "|  Roll No | Name                 |    Marks |\n";
        std::cout << "|----------|----------------------|----------|\n";
        for (const auto& s : students) {
            s.display();
        }
        std::cout << "=======================================================\n";
    }

    // Sort by Roll Number using Merge Sort (Stable, O(N log N))
    void sortByRollNo() {
        if (!students.empty()) {
            mergeSortRoll(students, 0, static_cast<int>(students.size()) - 1);
            std::cout << "\n[Success] Records sorted by Roll No using Merge Sort O(N log N).\n";
        }
    }

    // Sort by Marks descending using Insertion Sort (Stable, O(N^2))
    void sortByMarksDescending() {
        int n = static_cast<int>(students.size());
        for (int i = 1; i < n; ++i) {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && students[j].marks < key.marks) { // Descending
                students[j + 1] = students[j];
                j--;
            }
            students[j + 1] = key;
        }
        std::cout << "\n[Success] Records ranked by Marks (Merit List) using Insertion Sort.\n";
    }

    // Search by Roll Number using Binary Search (Requires sorted by roll number)
    int searchByRollNo(int roll) {
        sortByRollNo(); // Ensure prerequisite
        int left = 0, right = static_cast<int>(students.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (students[mid].rollNo == roll) return mid;
            if (students[mid].rollNo < roll) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    const Student* getStudent(int idx) const {
        if (idx >= 0 && idx < static_cast<int>(students.size())) return &students[idx];
        return nullptr;
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << " IC-307D Data Structures LAB - Student Record Manager\n";
    std::cout << " Student: Samarth Dubey | Roll No: IC-2K25-75\n";
    std::cout << "========================================================\n";

    StudentRecordManager sm;
    // Populate sample student dataset
    sm.addStudent(104, "Aarav Sharma", 88.5);
    sm.addStudent(101, "Samarth Dubey", 96.0);
    sm.addStudent(108, "Priya Patel", 91.5);
    sm.addStudent(103, "Rohan Verma", 79.0);
    sm.addStudent(105, "Ananya Joshi", 94.0);

    sm.displayTable("Original Unsorted Records");

    // 1. Sort by Roll No using Merge Sort
    sm.sortByRollNo();
    sm.displayTable("Sorted by Roll Number (Merge Sort)");

    // 2. Binary Search on Roll No
    int queryRoll = 101;
    std::cout << "\n[Query] Searching for Student with Roll No: " << queryRoll << "...\n";
    int idx = sm.searchByRollNo(queryRoll);
    if (idx != -1) {
        const Student* s = sm.getStudent(idx);
        std::cout << "  -> Record Found:\n";
        std::cout << "     Name: " << s->name << " | Marks: " << s->marks << "%\n";
    } else {
        std::cout << "  -> Record not found.\n";
    }

    // 3. Rank students by Marks using Insertion Sort
    sm.sortByMarksDescending();
    sm.displayTable("Merit Ranking by Marks (Insertion Sort)");

    return 0;
}
