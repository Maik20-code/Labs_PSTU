#include <iostream>
using namespace std;
int main() {
	int n, o;
	cin >> n;
	o=0;
	while(n>0){
	    o=o*10 + n%10;
        n/=10;
    }
    cout<<o<<endl;
	return 0;
}
