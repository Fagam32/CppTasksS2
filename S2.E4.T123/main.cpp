#include <iostream>
#include <ctime>
#include <iomanip>

void task1();

void task23();

int binarySearch(int a[], int item, int low, int high);

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
                task23();
                break;
            case 3:
                task23();
                break;
            default:
                cout << "Wrong command" << endl;
                break;
        }
    }
    return 0;
}

//Insert sort

void task1() {
    srand(time(nullptr));
    int a[20];
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 100;
        cout << setw(4) << a[i];
    }
    cout << endl;

    for (int i = 0; i < 20; i++) {
        int currentMin = i;
        for (int j = i; j < 20; j++) {
            if (a[j] < a[currentMin])
                currentMin = j;
        }
        int tmp = a[i];
        a[i] = a[currentMin];
        a[currentMin] = tmp;
        cout << setw(4) << a[i];
    }
    cout << endl;
}

void task23() {
    srand(time(nullptr));
    int a[20];
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 100;
        cout << setw(4) << a[i];
    }
    cout << endl;

    for (int i = 1; i < 20; ++i) {
        int j = i - 1;
        int selected = a[i];

        int loc = binarySearch(a, selected, 0, j);

        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }

    for (int i = 0; i < 20; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int binarySearch(int a[], int item, int low, int high) {
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

