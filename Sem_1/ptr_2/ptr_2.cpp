#include <iostream>
using namespace std;
int main() {
	int a, b, temp;
	cin>>a>>b;
	int *aPtr=&a;
	int *bPtr=&b;
	temp=*aPtr;
	*aPtr=*bPtr;
	*bPtr=temp;
	cout<<*aPtr<<endl;
	cout<<*bPtr<<endl;
	return 0;
}
