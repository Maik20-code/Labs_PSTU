#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int a[n]={5,2,4,6,0,1,3};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	int min_a, max_a;
	min_a=a[0];
	max_a=a[0];
	for (int i=0; i<n; i++){
	    if (a[i]>max_a){max_a=a[i];}
	    if (a[i]<min_a){min_a=a[i];}
	}
	cout<<max_a<<endl;
	cout<<min_a<<endl;
	
	return 0;
}
