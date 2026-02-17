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
	int max, cnt;
	cnt=1;
	max=a[0];
	for (int i=1; i<n; i++){
	    if (a[i]>max){
	        max=a[i];
	        cnt=1;
	    }
	    else if (a[i]==max){cnt+=1;}
	}
	cout<<endl;
	cout<<"Max: "<<max<<endl;
	cout<<"Count: "<<cnt<<endl;
	return 0;
}
