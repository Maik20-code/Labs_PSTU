#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int key;
	int a[n]={5,2,4,6,0,1,3};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	for (int i=1; i<n; i++){
	    key = a[i];
	    int j=i-1;
	    while(j>=0 && a[j]>key)
	    {
	        a[j+1]=a[j];
	        j--;
	    }
        a[j+1]=key;
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
