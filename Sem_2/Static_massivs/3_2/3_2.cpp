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
	int tmp, p, q;
	cin>>p>>q;
	while (p<q){
	    tmp=a[p];
	    a[p]=a[q];
	    a[q]=tmp;
	    p+=1;
	    q-=1;
	}
	for (int i=0; i<n; i++){
	    cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
