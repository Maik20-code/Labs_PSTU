#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a;
    int *aptr=&a;
    cin >> b;
    *aptr=b;
    cout<<a<<endl;
	return 0;
}
