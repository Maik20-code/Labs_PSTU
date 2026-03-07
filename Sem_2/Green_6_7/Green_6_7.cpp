#include <iostream>
#include <cstring>
using namespace std;
bool isLetter(char c){
    return(c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main() {
	char s[256];
	cout<<"Введите строку с точкой в конце:"<<endl;
	cin.getline(s, 256);
	int len=strlen(s);
	if (len>0 && s[len-1]=='.'){
	    s[len-1]='\0';
	    len--;
	}
	cout<<"\nИсходная строка: "<<s<<endl;
	for (int i=0; i<len-1; i++){
	    for (int j=0; j<len-i; j++){
	        if (isLetter(s[j]) && isLetter(s[j+1]) && s[j] > s[j+1]){
	            char t = s[j];
	            s[j] = s[j+1];
	            s[j+1] = t;
	        }
	    }
	}
	cout<<"Результат: "<<s<<endl;
	return 0;

}
