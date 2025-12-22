#include <iostream>
using namespace std;
int main() {
	int n, x, max, min;
	int *xPtr=&x;
	cin>>n;
	cin>>*xPtr;
	max=*xPtr;
	min=*xPtr;
	for (int i=2; i<=n; i++){
	    cin>>*xPtr;
	    if (*xPtr>max){max=*xPtr;}
	    else if (*xPtr<min){min=*xPtr;}
	}
	cout<<max<<endl;
	cout<<min<<endl;
	return 0;
}
