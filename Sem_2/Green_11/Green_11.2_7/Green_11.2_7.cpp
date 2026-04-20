#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
struct ListElem {
	int data;
	ListElem* next;
	ListElem* prev;
};
struct list {
	ListElem* head = nullptr;
	ListElem* tail = nullptr;
	unsigned int size = 0;
};
void createList(list& lst) {
	lst.head = nullptr;
	lst.tail = nullptr;
	lst.size = 0;
	cout << "Создан пустой двунаправленный список" << endl;
}
void printList(const list& lst) {
	if (lst.head == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	ListElem* current = lst.head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
void printListReverse(const list& lst) {
	if (lst.tail == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	ListElem* current = lst.tail;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->prev;
	}
	cout << endl;
}
void pushBack(list& lst, const int& data) {
	ListElem* newElem = new ListElem;
	newElem->data = data;
	newElem->next = nullptr;
	newElem->prev = lst.tail;
	if (lst.tail == nullptr) {
		lst.head = newElem;
		lst.tail = newElem;
	}
	else {
		lst.tail->next = newElem;
		lst.tail = newElem;
	}
	lst.size++;
}
void pushFront(list& lst, const int& data) {
	ListElem* newElem = new ListElem;
	newElem->data = data;
	newElem->next = lst.head;
	newElem->prev = nullptr;
	if (lst.head == nullptr) {
		lst.head = newElem;
		lst.tail = newElem;
	}
	else {
		lst.head->prev = newElem;
		lst.head = newElem;
	}
	lst.size++;
}
void popFront(list& lst) {
	if (lst.head == nullptr) {
		cout << "Нечего удалять из пустого списка!" << endl;
		return;
	}
	ListElem* remove = lst.head;
	lst.head = lst.head->next;
	if (lst.head != nullptr) {
		lst.head->prev = nullptr;
	}
	if (remove == lst.tail) {
		lst.tail = nullptr;
	}
	delete remove;
	lst.size--;
	cout << "Элемент из начала удален!" << endl;
}
void popBack(list& lst) {
	if (lst.tail == nullptr) {
		cout << "Нечего удалять из пустого списка!" << endl;
		return;
	}
	ListElem* remove = lst.tail;
	lst.tail = lst.tail->prev;
	if (lst.tail != nullptr) {
		lst.tail->next = nullptr;
	}
	if (remove == lst.head) {
		lst.head = nullptr;
	}
	delete remove;
	lst.size--;
	cout << "Элемент из конца удален!" << endl;
}
void addElem(list& lst, const int& data) {
	pushBack(lst, data);
	cout << "Элемент "<<data<<" добавлен в конец списка!" << endl;
}
void saveListToFile(const list& lst, const string& filename) {
	ofstream file(filename);
	ListElem* current = lst.head;
	while (current != nullptr) {
		file << current->data << endl;
		current = current->next;
	}
	file.close();
	cout << "Список сохранен в файл: " << filename << endl;
}
void destroyList(list& lst) {
	while (lst.head != nullptr) {
		popFront(lst);
	}
	cout << "Список уничтожен!" << endl;
}
void restoreListFromFile(list& lst, const string& filename) {
	ifstream file(filename);
	destroyList(lst);
	int data;
	while (file >> data) {
		pushBack(lst, data);
	}
	file.close();
	cout << "Список восстановлен из файла: " << filename << endl;
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	list myList;
	createList(myList);
	printList(myList);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		pushBack(myList, i);
	}
	cout << "Список с элементами: ";
	printList(myList);
	cout << endl;
	popFront(myList);
	cout << "Список после удаления первого элемента: ";
	printList(myList);
	popBack(myList);
	cout << "Список после удаления последнего элемента: ";
	printList(myList);
	cout << endl;
	pushFront(myList, 100);
	cout << "Список с новым элементом в начале: ";
	printList(myList);
	addElem(myList, 200);
	cout << "Список с новым элементом в конце: ";
	printList(myList);
	cout << endl;
	saveListToFile(myList, "list.txt");
	cout << endl;
	destroyList(myList);
	cout << endl;
	cout << "Список после уничтожения: ";
	printList(myList);
	cout << endl;
	restoreListFromFile(myList, "list.txt");
	cout << "Восстановленный список: ";
	printList(myList);
	cout << endl;
	destroyList(myList);
	printList(myList);
	return 0;
}
