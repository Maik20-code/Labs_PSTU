#include <iostream>
using namespace std;
int main() {
	float a, b, s;
	cin>>a>>b;
	float *aPtr=&a;
	float *bPtr=&b;
    s=*aPtr+*bPtr;
	cout<<s<<endl;
	return 0;
}
