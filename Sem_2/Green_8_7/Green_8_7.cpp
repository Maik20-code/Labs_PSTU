#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string lastName = "?";
    string firstName = "?";
    string patronymic = "?";
    string address = "?";
    string group = "?";
    float rating = 0.0;

    void print() {
        cout << "    Фамилия: \t" << lastName << endl;
        cout << "        Имя: \t" << firstName << endl;
        cout << "   Отчество: \t" << patronymic << endl;
        cout << "      Адрес: \t" << address << endl;
        cout << "     Группа: \t" << group << endl;
        cout << "    Рейтинг: \t" << rating << endl;
    }
};

Student* deleteByRating(Student* students, int& size, float minRating) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].rating < minRating) {
            count++;
        }
    }

    Student* newStudents = new Student[size - count];

    for (int i = 0, j = 0; i < size; i++) {
        if (students[i].rating >= minRating) {
            newStudents[j] = students[i];
            j++;
        }
    }

    delete[] students;
    size -= count;
    return newStudents;
}

Student* addElement(Student* students, int& size) {
    string lastName, firstName, patronymic, address, group, ratingStr;

    cout << "\nВведите данные нового студента:" << endl;
    cout << "Фамилия: "; getline(cin, lastName);
    cout << "Имя: "; getline(cin, firstName);
    cout << "Отчество: "; getline(cin, patronymic);
    cout << "Адрес: "; getline(cin, address);
    cout << "Группа: "; getline(cin, group);
    cout << "Рейтинг: "; getline(cin, ratingStr);

    Student newStudent = { lastName, firstName, patronymic, address, group, stof(ratingStr) };

    cout << "\nДобавлен новый студент:" << endl;
    newStudent.print();
    cout << endl;

    Student* newStudents = new Student[size + 1];

    for (int i = 0; i < size; i++) {
        newStudents[i] = students[i];
    }
    newStudents[size] = newStudent;

    size += 1;
    delete[] students;
    return newStudents;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    fstream file("Spisok.txt");
    string buff;

    int studentCount = 10;
    Student* students = new Student[studentCount];

    string lastName, firstName, patronymic, address, group, ratingStr;

    for (int i = 0; i < studentCount; i++) {
        getline(file, lastName);
        getline(file, firstName);
        getline(file, patronymic);
        getline(file, address);
        getline(file, group);
        getline(file, ratingStr);

        students[i] = { lastName, firstName, patronymic, address, group, stof(ratingStr) };

        getline(file, buff);
    }

    cout << "=== Исходные данные ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }

    float minRating = 3.8;
    students = deleteByRating(students, studentCount, minRating);
    cout << "\n=== После удаления студентов с рейтингом < " << minRating << " ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }
    cin.ignore();
    students = addElement(students, studentCount);

    cout << "\n=== После добавления студента ===" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        students[i].print();
    }

    delete[] students;
    return 0;
}
