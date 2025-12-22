#include <iostream>
using namespace std;
int main() {
	int n, fact=1;
	cin>>n;
	int *fPtr=&fact;
	for (int i=1; i<=n; i++){
	    *fPtr*=i;
	}
	cout<<*fPtr<<endl;
	return 0;
}
