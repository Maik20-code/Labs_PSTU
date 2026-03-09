#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a=0.1, b=1.0;
    int k=10, n=10;
    double eps=0.0001;
    double x, y, sn, se;
    double step = (b-a)/k;
    for (int i=0;i<=k; i++){
        x=a+i*step;
        y=cos(x);
        sn=1.0;
        double an=1.0;
        for (int j=1; j<=n; j++){
            an *= (-x*x)/((2*j-1)*(2*j));
            sn += an;
        }
        se=1.0;
        an=1.0;
        int j=1;
        while(abs(an)>eps){
        an *= (-x*x)/((2*j-1)*(2*j));
        sn += an;
        j++;
        }
        cout<<"X = "<<x<<endl;
        cout<<"Y = "<<y<<endl;
        cout<<"Сумма для n: "<<sn<<endl;
        cout<<"Сумма для eps: "<<se<<endl;
        cout<<"|Y-SN|"<<abs(y-sn)<<endl;
        cout<<"|Y-SE|"<<abs(y-se)<<endl;
        cout<<endl;
    }
    return 0;
    
}
