#include <iostream>
#include <cmath>
using namespace std;
int main() {
	float n, s, a;
	int c=1;
	bool flag=false;
	cin>>n>>s;
	while (c<=n && !flag){
	    a=sin(n+c/n);
	    a=round(a*10)/10;
	    cout<<n+c/n<<"|"<<a<<endl;
	    if (a==s){flag==true;}
	    else {c++;}
	}
	if (flag==true){cout<<"s найден"<<endl;}
	else {cout<<"s не найден"<<endl;}
	return 0;
}
