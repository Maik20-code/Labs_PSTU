#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    float x, fact, s;
    cin>>n>>x;
    s=1+x;
    fact=1;
    for (int i=2; i<=n; i++){
        fact*=i;
        s+=(pow(x,i)/fact);
    }
    cout<<s<<endl;
	return 0;
// Без фигни
    for (int i=2; i<=n; i++){
        fact*=i;
        int x_i=x;
        for (int j=2; j<=i; j++){
            x_i*=x;
        }  
        s+=(x_i/fact);
    }
    cout<<s<<endl;
	return 0;
}
