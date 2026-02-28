#include <iostream>
#include <cstdarg>
using namespace std;

double min(int type, int cnt, ...){
    va_list args;
    va_start(args, cnt);
    double min_val;
    if (type==0){
        min_val=va_arg(args, int);
        for (int i=1; i<cnt; i++){
            int n=va_arg(args, int);
            if (n<min_val){min_val=n;}
        }
    }
    else {
        min_val = va_arg(args, double);
        for (int i=1; i<cnt; i++){
            double n = va_arg(args, double);
            if (n<min_val){min_val=n;}
        }
    }
    va_end(args);
    return min_val;
}

int main() {
    cout<<"Мин. среди int (5 чисел): "<<min(0,5,-9,90,341,4,6)<<endl;
    cout<<"Мин. среди int (10 чисел): "<<min(0,10,55,-145,42,20,59,-4,59,67,41,10,40)<<endl;
    cout<<"Мин. среди int (12 чисел): "<<min(0,12,7,-59,64,88,2,-40,63,58,90,89,14,99)<<endl;
    cout<<"Мин. среди double (5 чисел): "<<min(1, 5, 0.01, 942.1, 10.01, 2.2,9.9)<<endl;
    cout<<"Мин. среди double (10 чисел): "<<min(1, 10, 50.1, 9.25, 51.22, 53.5, 1.33, 59.99, 0.44, 19.91, 3.4,10.1)<<endl;
    cout<<"Мин. среди double (12 чисел): "<<min(1, 12, 90.01, 49.9, 9.01, 12.02, 55.5, 5.20, 99.2, 69.91, 92.59, 3.33, 5.4, 0.4)<<endl;
    return 0;
}
