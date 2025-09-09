#include <iostream>

using namespace std;

int main(){
	
	int index;
	int max = 0;
	int candidate[5];
	
	for(int i = 0; i < 5; i++){
		cout << "Enter number of votes for candidate " << i + 1 << ": ";
		cin >> candidate[i];
	}
	
	cout << "\nCandidate scores board: "<< endl;
	for(int i = 0; i < 5; i++){
		cout << "Candidate " << i + 1 << ": " << candidate[i] << endl;
	}
	
	for(int i = 0; i < 5; i++){
		if(candidate[i] > max){
			max = candidate[i];
			index = i + 1;
		}
	}
	
	cout << "\nThe Winner candidate is " << index << " with votes " << max;
	
}
