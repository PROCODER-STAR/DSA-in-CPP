#include <iostream>
using namespace std;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int interpolationSearch(float arr[], int n, float x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);

        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of players: ";
    cin >> n;

    float averages[n];
    cout << "Enter batting averages of players:\n";
    for (int i = 0; i < n; i++) {
        cin >> averages[i];
    }

    insertionSort(averages, n);

    cout << "\nSorted batting averages (ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << averages[i] << " ";
    }
    cout << endl;

    float key;
    cout << "\nEnter batting average to search: ";
    cin >> key;

    int pos = interpolationSearch(averages, n, key);
    if (pos == -1) {
        cout << "Player with batting average " << key << " not found.\n";
    } else {
        cout << "Player(s) with batting average " << key << " found at position(s): ";

        int i = pos;
        while (i >= 0 && averages[i] == key) {
            i--;
        }
        i++;

        while (i < n && averages[i] == key) {
            cout << i << " ";  
            i++;
        }
        cout << endl;
    }

    return 0;
}

