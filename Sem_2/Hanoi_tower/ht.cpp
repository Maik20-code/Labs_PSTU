#include <iostream>
using namespace std;
void hanoy(int n, char start, char point, char t){
    if (n==0){cout<<"Переместить 1 диск с "<<start<<" на "<<point<<endl;}
    else {
        hanoy(n-1, start, point, t);
        cout<<"Переместить "<<n<<" диск с "<<start<<" на "<<point<<endl;
        hanoy(n-1, t, point, start);
    }
}

int main() {
    int n;
    cin>>n;
    if (n<=0){
        cout<<"ERROR!"<<endl;
        return 1;
    }
    hanoy(n,'A','B','C');
    return 0;
}
