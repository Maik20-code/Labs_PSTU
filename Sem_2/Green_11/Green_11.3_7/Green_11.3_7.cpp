#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
struct StackElem {
	int data;
	StackElem* next;
};
struct Stack {
	StackElem* topNode = nullptr;
	unsigned int size = 0;
};
void createStack(Stack& st) {
	st.topNode = nullptr;
	st.size = 0;
	cout << "Создан пустой стек" << endl;
}
void printStack(const Stack& st) {
	if (st.topNode == nullptr) {
		cout << "Стек пустой!" << endl;
	}
	StackElem* current = st.topNode;
	cout << "Вершина -> ";
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << "<- дно" << endl;
}
void push(Stack& st, const int& data) {
	StackElem* newElem = new StackElem;
	newElem->data = data;
	newElem->next = st.topNode;
	st.topNode = newElem;
	st.size++;
	cout << "Элемент " << data << " добавлен на вершину стека" << endl;
}
int pop(Stack& st) {
	if (st.topNode == nullptr) {
		cout << "Нечего удалять из пустого стека!" << endl;
		return -1;
	}
	StackElem* remove = st.topNode;
	int value = remove->data;
	st.topNode = st.topNode->next;
	delete remove;
	st.size--;
	cout << "Элемент " << value << " удален с вершины стека!" << endl;
	return value;
}
int top(Stack& st) {
	if (st.topNode == nullptr) {
		cout << "Стек пустой!" << endl;
		return -1;
	}
	return st.topNode->data;
}
void saveStackToFile(const Stack& st, const string& filename) {
	ofstream file(filename);
	StackElem* current = st.topNode;
	while (current != nullptr) {
		file << current->data << endl;
		current = current->next;
	}
	file.close();
	cout << "Стек сохранен в файл: " << filename << endl;
}
void destroyStack(Stack& st) {
	while (st.topNode != nullptr) {
		StackElem* remove = st.topNode;
		st.topNode = st.topNode->next;
		delete remove;
	}
	st.size = 0;
	cout << "Стек уничтожен!" << endl;
}
void restoreStackFromFile(Stack& st, const string& filename) {
	ifstream file(filename);
	destroyStack(st);
	int* arr = new int[100];
	int count = 0;
	int data;
	while (file >> data) {
		arr[count++] = data;
	}
	for (int i = count - 1; i >= 0; i--) {
		StackElem* newElem = new StackElem;
		newElem->data = arr[i];
		newElem->next = st.topNode;
		st.topNode = newElem;
		st.size++;
	}
	delete[] arr;
	file.close();
	cout << "Стек восстановлен из файла: " << filename << endl;
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	Stack myStack;
	createStack(myStack);
	printStack(myStack);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		push(myStack, i);
	}
	cout << "Стек с элементами: ";
	printStack(myStack);
	cout << "Размер: " << myStack.size << endl;
	cout << "Вершина стека: " << top(myStack) << endl;
	cout << endl;
	cout << "Удаление с вершины: ";
	pop(myStack);
	cout << "Стек: ";
	printStack(myStack);
	cout << endl;
	cout << "Добавление элемента 100 на вершину: ";
	push(myStack, 100);
	printStack(myStack);
	cout << endl;
	saveStackToFile(myStack, "file.txt");
	cout << endl;
	destroyStack(myStack);
	cout << "Стек после уничтожения: ";
	printStack(myStack);
	cout << endl;
	restoreStackFromFile(myStack, "file.txt");
	cout << "Восстановленный стек: ";
	printStack(myStack);
	cout << "Размер: " << myStack.size << endl;
	cout << "Вершина стека: " << top(myStack) << endl;
	cout << endl;
	destroyStack(myStack);
	printStack(myStack);
	return 0;
}
