#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void createFile() {
    FILE* f = fopen("F1.txt", "w");

    fprintf(f, "Line number one\n");
    fprintf(f, "Apple is a fruit\n");
    fprintf(f, "Third line\n");
    fprintf(f, "Watermelon is red and sweet\n");
    fprintf(f, "Fifth line with text\n");
    fprintf(f, "Aster blooms in autumn\n");
    fprintf(f, "Seventh line\n");
    fprintf(f, "Stork arrived in spring\n");
    fprintf(f, "Ninth line\n");
    fprintf(f, "Orange is a tasty fruit\n");

    fclose(f);
    cout << "File F1.txt created!" << endl;
}

int countChars() {
    FILE* f = fopen("F2.txt", "r");

    char buf[256];
    int count = 0;

    if (fgets(buf, 256, f) != NULL) {
        while (buf[count] != ' ' && buf[count] != '\n' && buf[count] != '\0') {
            count++;
        }
    }

    fclose(f);
    return count;
}

int main() {

    createFile();
    cout << endl;

    FILE* in = fopen("F1.txt", "r");
    FILE* out = fopen("F2.txt", "w");

    char buf[256];
    int copiedCount = 0;

    while (fgets(buf, 256, in) != NULL) {
        if (buf[0] != 'A') {
            fputs(buf, out);
            copiedCount++;
        }
    }

    fclose(in);
    fclose(out);

    cout << "Copied lines to F2.txt: " << copiedCount << endl;
    cout << endl;

    int charCount = countChars();
    cout << "Number of characters in the first word of F2.txt: " << charCount << endl;

    return 0;
}
