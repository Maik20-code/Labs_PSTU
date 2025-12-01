#include <iostream>
using namespace std;
 
int main() 
{
    int n,p;
    cin>>n;
    p=1;
    if (n>0){
        for (int i=1; i<=n; i++){
            p*=i;
        }
        cout<<p<<endl;
    }
    else{
        cout<<"Невозможно посчитать произведние нат. чисел при n<=0"<<endl;
    }
    return 0;
}
