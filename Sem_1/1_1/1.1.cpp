#include <iostream>
using namespace std;
 
int main() 
{
    int a,b,c,max;
    cin>>a>>b>>c;
    if (a>b){
        max=a;
    }
    else{
        b=max;
    }
    if (c>max){
        max=c;
    }
    cout<<max<<endl;
    return 0;

}
