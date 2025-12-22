#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x, xPrev;
    double eps=0.000001;
    double lambda=-0.5;
    x=0.85;
    xPrev=0;
    while(abs(x-xPrev)>eps){
        xPrev=x;
        x=lambda*(xPrev - 1/(3+sin(3.6*xPrev)))+xPrev;
    }
    cout<<x<<endl;
    return 0;
}
