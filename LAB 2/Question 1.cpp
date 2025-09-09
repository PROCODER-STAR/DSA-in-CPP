#include <iostream>
using namespace std;
int main()
{
	int rows = 5;
	int cols = 4;
	int avg[5] = {0};
	int **arr = new int*[rows];
	for (int i = 0; i < rows; i++ ){
		arr[i] = new int[cols];
	}
	for (int i = 0; i <
	 rows; i++ ){
		cout << "\tEnter Marks of Student " << i + 1 << ": \n";
		for(int j = 0; j < cols; j++){
			cout << "Marks of Subject " << j + 1 << ": " << endl;
			cin >> arr[i][j];
		}
	}
	cout << "\n\tMarks Of Students: " << endl;
	for (int i = 0; i < rows; i++ ){
		cout << "\nStudent " << i + 1 << ": \n";
		for(int j = 0; j < cols; j++){
			cout << "Subject " << j + 1 << ": ";
			cout << arr[i][j] << endl;
		}
	}
		cout << "\n\t****Average marks of Students:**** \n";
	for (int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			avg[i] += arr[i][j];
		}
		cout << "Student " << i + 1 << ": " << (avg[i]) / cols << endl;
	}
	for(int i = 0; i < rows; i++){
		delete[] arr[i];
	}
	delete[] arr;
	arr = NULL;
	return 0;
}
