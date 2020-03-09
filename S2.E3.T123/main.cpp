#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iomanip>

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

// Delete all same integers in sorted array
void task1() {
    srand(time(nullptr));
    int array[50];
    for (int i = 0; i < 50; ++i) {
        array[i] = rand() % 30;
    }

    sort(array, array + 50);
    for (int i = 0; i < 50; i++) {
        cout << array[i] << " ";
    }
    cout << endl << "Result: ";
    vector<int> result;
    result.push_back(array[0]);
    for (int i = 1; i < 50; ++i) {
        if (array[i] == array[i - 1])
            continue;
        else
            result.push_back(array[i]);
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Put 10 the biggest numbers on main diagonal
void task2() {
    int matrix[10][10];
    int cheat[100];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matrix[i][j] = cheat[i * 10 + j] = rand() % 1000;
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << "________________________" << endl;
    sort(cheat, cheat + 100);

    for (int i = 0; i < 10; i++) {
        matrix[i][i] = cheat[99 - i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// You have 2*N numbers. It's known, that they can be split into pairs in such way that they have the same multiplication
// cout those pairs
void task3() {
    srand(time(nullptr));
    int array[20];
    int bigRandomNumber = rand() % 1000; // ATTENTION: CAN BE PRIME)
    cout << "BigRandomNumber: " << bigRandomNumber << endl;
    for (int i = 0; i < 10; i++) {
        while (true) {
            int tmp = rand() % (bigRandomNumber / 2);
            if (bigRandomNumber % tmp == 0) {
                array[i] = tmp;
                array[19 - i] = bigRandomNumber / tmp;
                break;
            }
        }
    }

    sort(array, array + 20);
    for (int i = 0; i < 10; ++i) {
        cout << "(" << array[i] << " : " << array[19 - i] << ")" << endl;
    }
}