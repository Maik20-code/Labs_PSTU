#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
struct ListElem {
    int data;
    ListElem* next_ptr;
};
struct list {
    ListElem* head = nullptr;
    ListElem* tail = nullptr;
    unsigned int size;
};
void createList(list& lst) {
    lst.head = nullptr;
    lst.tail = nullptr;
    lst.size = 0;
    cout << "Создан пустой список" << endl;
}
void printList(const list& lst) {
    if (lst.head == nullptr) {
        cout << "Список пустой" << endl;
        return;
    }
    ListElem* current = lst.head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next_ptr;
    }
    cout << endl;
}
void pushBack(list& lst, const int& data) {
    ListElem* newElem = new ListElem;
    newElem->data = data;
    newElem->next_ptr = nullptr;
    if (lst.tail == nullptr) {
        lst.head = newElem;
        lst.tail = newElem;
    }
    else {
        lst.tail->next_ptr = newElem;
        lst.tail = newElem;
    }
    lst.size++;
}
void popFront(list& lst) {
    if (lst.head == nullptr) {
        cout << "Нечего удалять из пустого списка!" << endl;
        return;
    }
    ListElem* remove = lst.head;
    lst.head = lst.head->next_ptr;
    if (remove == lst.tail) { lst.tail = nullptr; }
    delete remove;
    lst.size--;
    cout << "Элемент из начала удален" << endl;
}
void addElem(list& lst, const int& data) {
    pushBack(lst, data);
    cout << "Элемент: " << data << " добавлен в конец списка" << endl;
}
void saveListToFile(const list& lst, const string& filename) {
    ofstream file(filename);
    ListElem* current = lst.head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next_ptr;
    }
    file.close();
    cout << "Список сохранен в файл : " << filename << endl;
}
void destroyList(list& lst) {
    while (lst.head != nullptr) { popFront(lst); }
    cout << "Список уничтожен!" << endl;
}
void restoreListFromFile(list& lst, const string& filename) {
    ifstream file(filename);
    destroyList(lst);
    int data;
    while (file >> data) { pushBack(lst, data); }
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
    addElem(myList, 100);
    cout << "Список с новым элементом: ";
    printList(myList);
    saveListToFile(myList, "list.txt");
    cout << endl;
    destroyList(myList);
    cout << "Список после удаления: ";
    printList(myList);
    cout << endl;
    restoreListFromFile(myList, "list.txt");
    cout << endl;
    cout << "Список: ";
    printList(myList);
    destroyList(myList);
    printList(myList);
    return 0;
}
