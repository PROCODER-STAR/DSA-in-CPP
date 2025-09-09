#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target){
	for(int i = 0; i < n; i++){
		if(arr[i] == target){
			return i; //index if found
		}
	}
	return -1; //-1 if not found
}

int main(){

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
	
	int result  = LinearSearch(arr, n, target);
	if(result != -1){
		cout << "Target '" << target << "' found at index " << result << " :)" << endl;	
	}
	else{
		cout << "Target '" << target << "' not found :(" << endl;
	}
	
	return 0;
}
