#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int rows=4;
const int cols=4;
void fillArr(int arr[rows][cols])
{
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            arr[i][j]=rand()%10;
        }
    }
}
void printArr(int arr[rows][cols]){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
void swapRowAndCol(int arr[rows][cols], int rowIndx, int colIndx){
    for (int i=0; i<rows; i++){
        if (i!=rowIndx){swap(arr[rowIndx][i], arr[i][colIndx]);}
    }
}
int main() {
	int arr[rows][cols];
	srand(time(0));
	cout<<"Исходный массив: "<<endl;
	fillArr(arr);
	printArr(arr);
	bool found=false;
	for (int i=1; i<rows; i++){
	    for (int j=1; j<cols; j++){
	        if (arr[i][0]==arr[0][j]){
	            cout<<"Совпадение: строка "<<i+1<<" (первый элемент = "<<arr[i][0]<<") и столбца "<<j+1<<" (первый элемент = "<<arr[0][j]<<")"<<endl;
	            swapRowAndCol(arr, i, j);
	            found=true;
	            cout<<"Обмен строки "<<i+1<<" и столбца "<<j+1<<":"<<endl;
	            printArr(arr);
	        }
	    }
	}
	if (!found){
	    cout<<"Совпадений не найдено!"<<endl;
	}
	return 0;
}
