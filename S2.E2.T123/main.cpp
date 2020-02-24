#include <iostream>
#include <fstream>
#include <cstring>
#include "string.h"

void task1();

void task2();

void task3();

using namespace std;

int main() {
    int q;
    while (true) {
        cout << "Enter task" << endl;
        cin >> q;
        switch (q) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            default:
                cout << "Wrong command" << endl;
                break;
        }
    }
    return 0;
}

/*
 * Count and print arithmetic mean from file
 */
void task1() {
    cout << "Enter filename" << endl;
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Troubles with file" << endl;
        return;
    }
    int totalSum = 0, number = 0;
    while (!file.eof()) {
        int current;
        file >> current;
        totalSum += current;
        number++;
    }
    cout << (double) totalSum / number << endl;
    file.close();
}

/*
 * Print all rows with entered word
 */
void task2() {
    cout << "Enter filename" << endl;
    string filename;
    cin >> filename;
    char s[1024];
    cout << "Enter word";
    cin >> s;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Troubles with file" << endl;
        return;
    }
    char charLine[1024];
    while (!file.eof()) {
        file.getline(charLine, 1024, '\n');
        string tmp = charLine;

        if (tmp.find_first_of(s) - 1 > 0 && tmp.find_first_of(s) < tmp.length())
            cout << tmp << endl;
    }
}

/*
 * Find all question sentences
 */
void task3() {
    cout << "Enter filename" << endl;
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Troubles with file" << endl;
        return;
    }
    string sentence;
    while (!file.eof()) {
        string word;
        file >> word;
        if (word[word.length() - 1] == '.' || word[word.length() - 1] == '!')
            sentence.clear();
        else if (word[word.length() - 1] == '?') {
            sentence += word;
            cout << sentence << endl;
            sentence.clear();
        } else
            sentence += word;
    }
}
