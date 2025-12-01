#include <iostream>
using namespace std;
 
int main() 
{
    int n;
    cin>>n;
    int spc=n/2;
    int strs=1;
    for (int i=1; i<=(n+1)/2; i++){
        for (int j=0; j<spc; j++){
            cout<<" ";
        }
        spc--;
        for (int j=0; j<strs; j++){
            cout<<"*";
        }
        strs+=2;
        cout<<endl;
    }
    return 0;
}
