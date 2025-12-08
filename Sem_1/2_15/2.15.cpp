#include <iostream>
using namespace std;
int main() {
    int n,s,t;
    bool Snum=false;
    cin>>n>>s;
    while (n>0 && !Snum){
        t=n%10;
        if (s==t) {
            Snum=true;
            cout<<"Цифра найдена"<<endl;
        }
        else {n/=10;}
    }
    if (!Snum) {cout<<"Цифра не найдена"<<endl;}
	return 0;
}
