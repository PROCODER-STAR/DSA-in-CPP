#include <iostream>
using namespace std;
int main(){
	int member;	
	int books[]={0};
	
	cout << "Enter numbers of Members: ";
	cin >> member;
	
	int** arr = new int*[member];
	for(int i = 0; i < member; i++) {
		cout << "Enter no. Books for Member " << i + 1 << ": ";
		cin >> books[i];
		arr[i] = new int[books[i]];
	}
	
	for(int i = 0; i < member; i++){
		cout << "Enter " << books[i] << " Books for Member " << i + 1 << ":";
		for(int j = 0; j < books[i]; j++){
			cin >> arr[i][j];
		}
	}
	
	cout << "\nNo. Of Books Barrowed by Members: \n";
	for(int i = 0; i < member; i++){
		cout << "Member " << i + 1 << ": ";
		for(int j = 0; j < books[i]; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i < member; i++){
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}
