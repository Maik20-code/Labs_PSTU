#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int a[n]={5,2,4,6,0,1,3};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	int temp=0;
	for (int i=0; i<n; i++){
	    if (a[i]>=temp){temp=a[i];}
	}
	cout<<temp;
	return 0;
}
