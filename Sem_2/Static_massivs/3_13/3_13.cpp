#include <iostream>
using namespace std;

int main() {
	const int n=3;
	int a[n][n]={ {3, 7, 0}, {9, 4, 6}, {5, 1, 2} };
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int k=1;
    int tmp;
    cin>>k;
    if (k>=n){k=n-1;}
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i;j++){
            if (a[k][j]>a[k][j+1]){
                for (int r=0; r<n; r++){
                    tmp=a[r][j];
                    a[r][j]=a[r][j+1];
                    a[r][j+1]=tmp;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
