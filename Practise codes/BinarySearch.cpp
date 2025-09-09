#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int target){
	int lowerBound = 0;
	int UpperBound = n - 1;
	
    while (lowerBound <= UpperBound) {
        int mid = (lowerBound + UpperBound) / 2;

        if (arr[mid] == target){	
            return mid; // index if found
		}
        else if (arr[mid] < target)
            lowerBound = mid + 1;
        else
            UpperBound = mid - 1;
    }
    return -1; // -1 if not found
}

int main() {
    int n;
    int target;
    
	cout << "Enter size of the array: " << endl;
	cin >> n;
	
	int arr[n];
	
	cout << "Enter elements of the array : " << endl;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << "Enter the Target to search for: " << endl;
	cin >> target;
	
	int result = BinarySearch(arr, n, target);
    if (result != -1){
        cout << "Target '" << target << "' Found at index " << result << " :)" << endl;
	}
    else{
        cout << "Target '" << target << "' Not found :(" << endl;
	}

    return 0;
}
