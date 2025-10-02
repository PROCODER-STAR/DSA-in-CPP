#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; 
}

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    int patientIDs[n]; 
    cout << "Enter patient IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> patientIDs[i];
    }

    insertionSort(patientIDs, n);

    cout << "\nSorted patient IDs:\n";
    for (int i = 0; i < n; i++) {
        cout << patientIDs[i] << " ";
    }
    cout << endl;

    int key;
    cout << "\nEnter patient ID to search: ";
    cin >> key;

    int pos = binarySearch(patientIDs, n, key);
    if (pos == -1) {
        cout << "Patient record not found.\n";
    } else {
        cout << "Patient record found at index " << pos << ".\n";
    }

    return 0;
}

