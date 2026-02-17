#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	const int n=10;
	int a[n];
	int r_min=0;
	int r_max=100;
	for (int i=0; i<n; i++){
	    a[i]=((double)rand()/RAND_MAX)*(r_max-r_min)+r_min;
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	int tmp;
	for (int i=0; i<n/2; i++){
	    tmp=a[i];
	    a[i]=a[n-1-i];
	    a[n-1-i]=tmp;
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
