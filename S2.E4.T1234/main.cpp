#include <iostream>
#include <ctime>

using namespace std;

void task1();

void task2();

void task3();

void task4();

void solve(int n, int sum1, int sum2);

int main() {
    int q;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
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
            case 4:
                task4();
                break;
            default:
                cout << "Wrong command" << endl;
                break;
        }
    }
#pragma clang diagnostic pop
    return 0;
}

// Find in [N,M] number with the biggest number of delimiters
void task1() {
    int n, m;
    cout << "Enter m" << endl;
    cin >> m;
    cout << "Enter n" << endl;
    cin >> n;

    int currentMaxNumber = -1;
    int currentMaxDelimiters = 0;

    for (int i = m; i <= n; i++) {

        int currentNumber = i;
        int currentDelimiters = 0;
        while (currentNumber != 1) {
            for (int j = 2; j <= currentNumber; j++) {
                cout << currentNumber << endl;
                if (currentNumber % j == 0) {
                    currentDelimiters++;
                    currentNumber = currentNumber / j;
                    j = 1;
                }
            }
            cout << "Number: " << i << " Delim: " << currentDelimiters << endl;
            if (currentMaxDelimiters < currentDelimiters) {
                currentMaxDelimiters = currentDelimiters;
                currentMaxNumber = i;
            }
        }
    }

    cout << "Number with max number of delimiters is: " << currentMaxNumber << endl <<
         "With: " << currentMaxDelimiters << " delimiters" << endl;
}

// Guess the number
void task2() {
    srand(time(nullptr));
    int randomNumber = rand() % 100;
    int userNumber = -1;
    while (userNumber != randomNumber) {
        cout << "Enter your number" << endl;
        cin >> userNumber;
        if (userNumber > randomNumber) {
            cout << "Your number is too big, make it lower" << endl;
            continue;
        }
        if (userNumber < randomNumber) {
            cout << "Your number is too low, make it bigger" << endl;
            continue;
        }
    }
    cout << "Congratz, number was: " << randomNumber << endl;
}

int N, mas[10];
bool result = false;

// You have N < 10 stones, their weights are less than 10_000, is it able to put them into 2 packs with the same sum of weights?
void task3() {
    cout << "Enter N" << endl;
    cin >> N;
    cout << "Enter N stones";
    for (int i = 0; i < N; i++) {
        cin >> mas[i];
    }
    solve(0, 0, 0);
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    result = false;
}

void solve(int n, int sum1, int sum2) {
    if (n == N) {
        if (sum1 - sum2 == 0) {
            result = true;
        }
        return;
    }
    solve(n + 1, sum1 + mas[n], sum2);
    solve(n + 1, sum1, sum2 + mas[n]);
}


// Didn't understand the task :( Where's to take vocabulary?
void task4() {

}
