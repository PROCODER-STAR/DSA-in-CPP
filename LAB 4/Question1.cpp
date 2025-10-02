#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
		break; 
		}
    }
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);

        if (arr[pos] == x){
            return pos;
		}
        if (arr[pos] < x){
            low = pos + 1;
		}
        else{
            high = pos - 1;
		}
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of songs: ";
    cin >> n;

    int songs[n];  
    cout << "Enter durations of songs (in seconds):\n";
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    bubbleSort(songs, n);

    cout << "\nSorted playlist (shortest to longest):\n";
    for (int i = 0; i < n; i++) {
        cout << songs[i] << " ";
    }
    cout << endl;

    int key;
    cout << "\nEnter song duration to search: ";
    cin >> key;

    int pos = interpolationSearch(songs, n, key);
    if (pos == -1) {
        cout << "Song with duration " << key << " not found.\n";
    } else {
        cout << "Song(s) with duration " << key << " found at position(s): ";
        
        int i = pos;
        while (i >= 0 && songs[i] == key) {
            i--;
        }
        i++;
    
	    while (i < n && songs[i] == key) {
            cout << i << " "; 
            i++;
        }
        cout << endl;
    }
    return 0;
}
