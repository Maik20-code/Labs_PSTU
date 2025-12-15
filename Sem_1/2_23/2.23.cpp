#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float a, n, max;
	int i=2;
	int num=1;
	int c=1;
	cin>>n;
	max=sin(n+1/n);
	while (i<=n){
	    a=sin(n+i/n);
	    if (a<max){
	        max=a;
	        c=1;
	    }
	    else if(a==max){c++;}
	    i++;
	}
	cout<<"Число эл. с макс. значением: "<<c<<endl;
	return 0;
}
