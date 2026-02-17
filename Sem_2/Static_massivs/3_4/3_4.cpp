#include <iostream>
using namespace std;

int main() {
    const int n=7;
    int a[n]={1, 2, 3, 4, 5, 6, 7};
    bool sorted=true;
    for (int i=1; i<n; i++){
        if (a[i]<a[i-1]){
            sorted=false;
            break;
        }
    }
    cout<<endl;
    if (sorted){cout<<"Sorted!"<<endl;}
    else {cout<<"Non Sorted!"<<endl;}
}
