#include <iostream>

using namespace std;

int main(){
	int length;
	
	cout << "Enter the length of your name: " ;
	cin >> length;
	
	char *name = new char[length + 1];
	
	cout << "Enter your name: ";
	cin >> name;
	
	cout << "Your name character by character: " << endl;
	
	char *ptr = name;
	while( *ptr != '\0'){
		cout << *ptr << endl;
		ptr++;
	}
	
	delete[] name;
	name = nullptr;
	ptr = nullptr;
}
