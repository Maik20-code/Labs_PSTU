#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float a, b, c, D, x1, x2;
    cin>>a>>b>>c;
    D=pow(b,2) - 4*a*c;
    if (D>0){
        x1=(-b+sqrt(D))/(a*2);
        x2=(-b-sqrt(D))/(a*2);
        cout<< "1-й корень:"<< x1 << endl;
        cout<< "2-й корень:"<< x2 << endl;
    }
    else if (D==0){
        cout<<"Корень:"<<(-b/(2*a))<<endl;
    }
    else {cout<<"Не сущ-т корней при D<0"<<endl;}
	return 0;
}
