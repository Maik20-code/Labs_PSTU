#include <iostream>
using namespace std;

void division(int a, int b){
    cout<<a/b<<endl;
}
void division(double a_re, double a_im, double b_re, double b_im, double& re, double& im){
    double d=b_re*b_re + b_im*b_im;
    re=(a_re*b_re+a_im*b_im)/d;
    im=(a_im*b_re-a_re*b_im)/d;
}
int main() {
    double r, i;
    cout<<"13 / 2 = ";
    division(13,2);
    division(4, 3, 1, 1, r, i);
    cout<<"4 + 3i / (1 + i) = "<<r<<" + "<<i<<"i"<<endl;
    division(5,0,2,0,r,i);
    cout<<"5 / 2 = "<<r<<" + "<<i<<"i"<<endl;
    return 0;
}
