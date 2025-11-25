#include <iostream>
using namespace std;
 
int main() 
{
    int n,s;
    cin>>n;
    if (n>0){
        for (int i=1; i<=n; i++){
            s+=i;
        }
        cout<<s<<endl;
    }
    else{
        cout<<"Невозможно посчитать сумму нат. чисел при n<=0"<<endl;
    }
    return 0;
}
