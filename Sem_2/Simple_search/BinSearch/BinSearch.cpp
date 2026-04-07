# include <iostream>
# include <Windows.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int x) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) low = mid + 1;
		else high = low - 1;
	}
	return -1;
}
int binarySearchRecursive(int arr[], int low, int high, int x) {
	if (low > high) return -1;
	int mid = low + (high - low) / 2;
	if (arr[mid] == x) return mid;
	if (arr[mid] < x) return binarySearchRecursive(arr, mid + 1, high, x);
	return binarySearchRecursive(arr, low, mid - 1, x);
}
void printArr(int arr[], int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) cout << ", ";
	}
	cout << "]" << endl;
}
void insertionSort(int arr[], int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int arr[] = { 42, 53, 14, 66, 3, 234, 9, 2, 47 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 53;
	insertionSort(arr, n);
	cout << "Массив: " << endl;
	printArr(arr, n);
	cout << endl;
	int res = binarySearch(arr, 0, n - 1, x);
	if (res == -1) cout << "Элемент " << x << " не найден" << endl;
	else cout << "Элемент " << x << " найден по индексу " << res << endl;
	int resr = binarySearchRecursive(arr, 0, n - 1, x);
	if (resr == -1) cout << "Элемент " << x << " не найден" << endl;
	else cout << "Элемент " << x << " найден по индексу " << resr << endl;
	return 0;
}
