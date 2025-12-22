#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float x, xPrev;
	x=0.85;
	xPrev=-1;
	double eps=0.000001;
	while (abs(x-xPrev)>eps){
	    xPrev=x;
	    x=xPrev - (xPrev - (1/(3+sin(3.6*xPrev))))/(1+(3.6*cos(3.6*xPrev))/pow(3+sin(3.6*xPrev),2));
	}
	cout<<x<<endl;
    return 0;
}
