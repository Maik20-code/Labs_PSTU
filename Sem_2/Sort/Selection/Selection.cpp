#include <iostream>
using namespace std;

int main() {
	const int n=7;
	int tmp, min_index;
	int a[n]={5,2,4,6,0,1,3};
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	for (int i=0; i<n-1; i++){
	    min_index = i;
	    for (int j=i+1; j<n; j++){
	        if (a[j]<a[min_index]){min_index=j;}
	    }
	    tmp=a[min_index];
	    a[min_index]==a[i];
	    a[i]=tmp;
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<endl;
	}
	cout<<endl;
	return 0;
}
