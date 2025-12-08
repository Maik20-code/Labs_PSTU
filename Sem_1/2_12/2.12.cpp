#include <iostream>
using namespace std;
int main() {
    int n, t, max, min;
	cin >> n >> t;
	min=t;
	max=t;
	for (int i=2; i<=n; i++){
	    cin >> t;
	    if (t>max) {max=t;}
	    else {min=t;}
	}
	cout << "Максимальное число: "<< max << endl;
	cout << "Минимальное число: "<< min << endl;
	return 0;
}
