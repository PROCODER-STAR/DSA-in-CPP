#include <iostream>
using namespace std;

int InterpolationSearch(int arr[], int n, int target) {
    int lowerBound = 0;
	int UpperBound = n - 1;

    while (lowerBound <= UpperBound && target >= arr[lowerBound] && target <= arr[UpperBound]) {
        int pos = lowerBound + ((double)(target - arr[lowerBound]) * (UpperBound - lowerBound)) 
                          / (arr[UpperBound] - arr[lowerBound]);

        if (arr[pos] == target){
            return pos; //index if found
		}
        if (arr[pos] < target){
            lowerBound = pos + 1;
		}
        else{
            UpperBound = pos - 1;
		}
    }
    return -1; // -1 if not found
}

int main() {
    int n;
    int target;
    
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array: ";
    
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the Target to search for: ";
    cin >> target;

    int result = InterpolationSearch(arr, n, target);
    if (result != -1){
        cout << "Target '" << target << "' Found at index " << result << " :)" << endl;
	}
    else{
        cout << "Target '" << target << "' Not found :(" << endl;
	}

    return 0;
}
