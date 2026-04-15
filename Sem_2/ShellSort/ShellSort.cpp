#include <iostream>
#include <windows.h>
using namespace std;
void shellSort(int arr[], int n) {
	for (int h = n / 2; h > 0; h /= 2) {
		for (int i = h; i < n; i++) {
			int tmp = arr[i];
			int j;
			for (j = i; j >= h && arr[j - h] > tmp; j -= h) {
				arr[j] = arr[j - h];
			}
			arr[j] = tmp;
		}
	}
}
void printArray(int arr[], int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) cout << ", ";
	}
	cout << "]" << endl;
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	int arr[] = { 12, 34, 54, 2, 3, 7, 9, 1, 25, 18 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Исходный массив: ";
	printArray(arr, n);
	shellSort(arr, n);
	cout << "Отсортированный массив: ";
	printArray(arr, n);
	return 0;
}
