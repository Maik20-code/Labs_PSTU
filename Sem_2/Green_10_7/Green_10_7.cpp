#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int rows, cols;
	cout<<"Введите кол-во строк и столбцов: ";
	cin>>rows>>cols;
	int** arr=new int*[rows];
	srand(time(0));
	cout<<"Исходный массив"<<endl;
	for (int i=0; i<rows; i++){
	    arr[i]=new int[cols];
	    for (int j=0; j<cols; j++){
	        arr[i][j]=rand()%10;
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	cout<<"Введите номер столбца для удаления от 0 до "<<cols<<" : "<<endl;
	int delCol;
	cin>>delCol;
	cout<<"Массив после удаления столбца "<<delCol<<endl;
	for (int i=0; i<rows; i++){
	    for (int j=delCol-1; j<cols; j++){
	        arr[i][j]=arr[i][j+1];
	    }
	    for (int j=0; j<cols-1; j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	for (int i=0; i<rows; i++){
	    delete[] arr[i];
	}
	delete[] arr;
    return 0;
}
