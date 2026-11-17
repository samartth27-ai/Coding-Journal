
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = 4;
    int mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid;
            found = 1;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found == 0) {
        cout << "Element not found";
    }

    return 0;
}
