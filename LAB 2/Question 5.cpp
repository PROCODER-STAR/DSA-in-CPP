#include<iostream>
using namespace std;
int main(){
	int n,m;
	cout<<"Enter the number of rows and columns "<<endl;
	cin>>n>>m;
int** arr=new int*[n];
int** arr1=new int*[n];
	for (int i=0;i<n;i++){
		arr[i]=new int[m];
		arr1[i]=new int[m];
	}
	cout<<"Enter the Elements for matrix 1"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	cout<<"Enter the Elements for matrix 2"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr1[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		arr[i][j]=arr[i][j]-arr1[i][j];
	}
}
	cout<<"\n The Final Matrix after subtracting is:"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" " ;
		}
		cout<<endl;
	}  for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] arr1[i];
    }
    delete[] arr;
    delete[] arr1;
    return 0;
}
