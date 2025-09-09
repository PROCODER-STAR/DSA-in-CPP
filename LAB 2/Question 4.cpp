#include <iostream>
using namespace std;

int main (){
	int size;
	cout<<"Enter no of items:";
	cin>>size;
	
	double *price =new  double[size];
	double total=0;
	for(int i =0 ;i<size;i++){
		cout<<"\nEnter price of item:"<<i+1<<" : ";
		cin>>price[i];
		total+=price[i];
	}
	cout<<"Total BILL: "<<total<<endl;
	int afterTax=total+total*5/100;
	
	cout<<"Total Bill After applying 5% sales tax: "<<afterTax;
	
	delete[] price;
}
