#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int n=50;
	srand(time(0));
	int a[n];
	int r_min=0;
	int r_max=100;
	for(int i=0; i<n; i++){
	    a[i]=((double)rand()/RAND_MAX) * (r_max-r_min) + r_min;
	    cout<<a[i]<<" ";
    }
    cout<<endl;
    int key;
	cin>>key;
	int p=n;
	for (int i=n-1; i<=0; i--){
	    if (a[i]==0){
	        p-=1;
	        for (int j=i; j<p; j++){
	            a[j]=a[j+1];
	        }
	    break;
	    }
	}
	for (int i=0; i<n-1; i++){
	    a[key+1]=100;
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
