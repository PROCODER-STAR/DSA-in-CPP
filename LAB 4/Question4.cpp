#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; // found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int n;
    cout << "Enter number of applicants: ";
    cin >> n;

    int scores[n]; 
    cout << "Enter entrance test scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    selectionSort(scores, n);

    cout << "\nSorted scores (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    int key;
    cout << "\nEnter score to check admission: ";
    cin >> key;

    int pos = binarySearch(scores, n, key);
    if (pos == -1) {
        cout << "Not Admitted\n";
    } else {
        cout << "Admitted\n";
    }

    return 0;
}
