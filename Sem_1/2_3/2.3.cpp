#include <iostream>
using namespace std;
 
int main() 
{
    int n,s=0,p;
    cin>>n;
    for (int i=1; i<=n; i++){
        p=1;
        for (int j=i; j<=i*2; j++){
            p*=j;
        }
        s+=p;
    }
    cout<<s<<endl;
    return 0;
}
