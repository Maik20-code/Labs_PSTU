# include <iostream>
# include <fstream>
# include <string>
# include <Windows.h>
using namespace std;
struct QueueElem {
	int data;
	QueueElem* next;
};
struct Queue {
	QueueElem* frontNode = nullptr;
	QueueElem* backNode = nullptr;
	unsigned int size = 0;
};
void createQueue(Queue& q) {
	q.frontNode = nullptr;
	q.backNode = nullptr;
	q.size = 0;
	cout << "Создана пустая очередь" << endl;
}
void printQueue(const Queue& q) {
	if (q.frontNode == nullptr) {
		cout << "Очередь пуста!" << endl;
		cout << "Начало -> <- конец " << endl;
		return;
	}
	QueueElem* current = q.frontNode;
	cout << "Начало -> ";
	while (current!= nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << "<- конец" << endl;
}
void push(Queue& q, const int& data) {
	QueueElem* newElem = new QueueElem;
	newElem->data = data;
	newElem->next = nullptr;
	if (q.backNode == nullptr) {
		q.frontNode = newElem;
		q.backNode = newElem;
	}
	else {
		q.backNode->next = newElem;
		q.backNode = newElem;
	}
	q.size++;
	cout << "Элемент " << data << " добавлен в конец очереди" << endl;
}
int pop(Queue& q) {
	if (q.frontNode == nullptr) {
		cout << "Нечего удалять из пустой очереди!" << endl;
		return -1;
	}
	QueueElem* remove = q.frontNode;
	int value = remove->data;
	q.frontNode = q.frontNode->next;
	if (q.frontNode == nullptr) {
		q.backNode = nullptr;
	}
	delete remove;
	q.size--;
	cout << "Элемент " << value << " удален из начала очереди!" << endl;
	return value;
}
int front(const Queue& q) {
	if (q.frontNode == nullptr) {
		cout << "Очередь пустая!" << endl;
		return -1;
	}
	return q.frontNode->data;
}
int back(const Queue& q) {
	if (q.backNode == nullptr) {
		cout << "Очередь пустая!" << endl;
		return -1;
	}
	return q.backNode->data;
}
void saveQueueToFile(const Queue& q, const string& filename) {
	ofstream file(filename);
	QueueElem* current = q.frontNode;
	while (current != nullptr) {
		file << current->data << endl;
		current = current->next;
	}
	file.close();
	cout << "Очередь сохранена в файл: " << filename << endl;
}
void destroyQueue(Queue& q) {
	while (q.frontNode != nullptr) {
		QueueElem* remove = q.frontNode;
		q.frontNode = q.frontNode->next;
		delete remove;
	}
	q.backNode = nullptr;
	q.size = 0;
	cout << "Очередь уничтожена!" << endl;
}
void restoreQueueFromFile(Queue& q, const string& filename) {
	ifstream file(filename);
	int data;
	while (file >> data) {
		QueueElem* newElem = new QueueElem;
		newElem->data = data;
		newElem->next = nullptr;
		if (q.backNode == nullptr) {
			q.frontNode = newElem;
			q.backNode = newElem;
		}
		else {
			q.backNode->next = newElem;
			q.backNode = newElem;
		}
		q.size++;
	}
	file.close();
	cout << "Очередь восстановлена из файла: " << filename << endl;
}
int main() {
	SetConsoleOutputCP(CP_UTF8);
	Queue myQueue;
	createQueue(myQueue);
	printQueue(myQueue);
	for (int i = 0; i < 10; i++) {
		push(myQueue, i);
	}
	cout << "Очередь с элементами:";
	printQueue(myQueue);
	cout << "Размер: " << myQueue.size << endl;
	cout << "Начало очереди (front): " << front(myQueue) << endl;
	cout << "Конец очереди (back): " << back(myQueue) << endl;
	cout << endl;
	cout << "Удаление из начала: ";
	pop(myQueue);
	cout << "Очередь: ";
	printQueue(myQueue);
	cout << "Добавление элемента 100 в конец: ";
	push(myQueue, 100);
	cout << "Очередь: ";
	printQueue(myQueue);
	saveQueueToFile(myQueue, "queue.txt");
	destroyQueue(myQueue);
	cout << endl;
	cout << "Очередь после уничтожения: ";
	printQueue(myQueue);
	cout << endl;
	restoreQueueFromFile(myQueue, "queue.txt");
	cout << "Очередь: ";
	printQueue(myQueue);
	cout << "Размер: " << myQueue.size << endl;
	cout << "Начало очереди (front): " << front(myQueue) << endl;
	cout << "Конец очереди (back): " << back(myQueue) << endl;
	cout << endl;
	destroyQueue(myQueue);
	printQueue(myQueue);
	return 0;
}
