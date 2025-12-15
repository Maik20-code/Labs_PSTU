#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
	int n,k;
	bool flag=true;
	while (n!=0){
	    cin>>k;
	    if (k!=0 && n>k){flag=false;}
	    n=k;
	}
	if (flag){
	    cout<<"Числа упорядоченны по возрастанию"<<endl;
	}
	else {cout<<"Числа не упорядоченны по возрастанию"<<endl;
	return 0;
}
