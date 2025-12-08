#include <iostream>
using namespace std;
int main() {
	int n, t, max;
	bool plusFirst = false; 
	bool minusFirsrt = false; 
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>t;
        if (!plusFirst && !minusFirsrt){
            if (t>0) {plusFirst = true;}
            else if (t<0) {minusFirsrt = true;}
        }
    }
    if (plusFirst) {cout<< "Сначала ввели положительное число " <<endl;}
    else if (minusFirsrt) {cout<<"Сначала ввели отрицательное число"<<endl;}
    else {cout<<"Все элементы нулевые"<<endl;}
    cout<<endl;
	return 0;
}
