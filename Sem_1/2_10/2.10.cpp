#include <iostream>
using namespace std;
int main() {
	int n, t, max;
	cin >>n;
	cin>>max;
	for (int i=2; i<=n; i++){
	    cin >> t;
	    if (t>max) {max=t;}
	}
	cout << "Максимальное число:"<< max << endl;
	return 0;
}
