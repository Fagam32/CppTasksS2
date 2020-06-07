#include <iostream>
#include <set>
#include <fstream>
#include <ctime>

using namespace std;

void task1();

void task2();

void task3();

void task4();

void solve(int n, int sum1, int sum2);

bool nextSet(int *a, int n, int k);

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
    set<string> vocabulary;
    string line;
    char alphabet[] = {
            'a', 'b', 'c', 'd', 'e',
            'f', 'g', 'h', 'i', 'j',
            'k', 'l', 'm', 'n', 'o',
            'p', 'q', 'r', 's', 't',
            'u', 'v', 'w', 'x', 'y',
            'z'
    };
    int numberOfchars[] = {10, 3, 5, 3, 5,
                           9, 2, 2, 8, 4,
                           6, 4, 5, 8, 10,
                           6, 6, 6, 5, 3,
                           1, 2, 1, 2, 1,
                           1};
    int costs[] = {1, 3, 2, 3, 2,
                   1, 5, 5, 1, 2,
                   2, 2, 2, 1, 1,
                   2, 2, 2, 2, 3,
                   10, 5, 10, 5, 10,
                   10};


    ifstream file(R"(C:\Users\ilya1\CLionProjects\S2.E5.T4\vocabulary.txt)");

    while (getline(file, line)) {
        vocabulary.insert(line);
    }
    file.close();

    //Getting letters
    srand(time(nullptr));

    char chosenLetters[8];

    for (int i = 0; i < 8; i++) {
        int random = rand() % 26;
        if (numberOfchars[random] > 0) {
            chosenLetters[i] = alphabet[random];
            numberOfchars[random]--;
            cout << chosenLetters[i] << " ";
        } else
            i--;
    }
    cout << endl;

    set<string> setOfWords;
    int maxWeight = -1;
    string answerWord;
    //generate all words from letters
    int setOfNumber[8];
    for (int wordLength = 8; wordLength > 0; wordLength--) {

        for (int i = 0; i < wordLength; i++)
            setOfNumber[i] = i + 1;

        setOfWords.clear();

        do {
            //convert numbers into word
            string q;
            for (int i = 0; i < wordLength; i++) {
                q.push_back(chosenLetters[setOfNumber[i] - 1]);
            }
            setOfWords.insert(q);
        } while (nextSet(setOfNumber, 8, wordLength));

        for (string item : setOfWords) {
            if (vocabulary.find(item) == vocabulary.end()) { //if not found
                continue;
            } else {
                //weight of found word
                int curWeight = 0;
                for (int i = 0; i < wordLength; i++) {
                    char c = item.at(i);
                    int q = 0;
                    for (; q < 26; q++) {
                        if (alphabet[q] == c)
                            break;
                    }
                    curWeight += costs[q];
                }

                if (curWeight > maxWeight) {
                    maxWeight = curWeight;
                    answerWord = item;
                }
            }
        }
    }
    cout << answerWord << " " << maxWeight << endl;
}

bool nextSet(int *a, int n, int k) {
    int edge, j, i, tmp;
    edge = k - 1;

    j = k;
    while ((j < n) && (a[edge] >= a[j])) ++j;

    if (j < n) {

        tmp = a[edge], a[edge] = a[j], a[j] = tmp;
    } else {

        for (i = k, j = n - 1; i < j; i++, j--) {
            tmp = a[i], a[i] = a[j], a[j] = tmp;
        }

        i = edge - 1;

        while (i >= 0 && a[i] >= a[i + 1]) --i;
        if (i < 0) return false;

        j = n - 1;

        while (j > i && a[i] >= a[j]) --j;

        tmp = a[i], a[i] = a[j], a[j] = tmp;

        for (i = i + 1, j = n - 1; i < j; i++, j--) {
            tmp = a[i], a[i] = a[j], a[j] = tmp;
        }
    }
    return true;
}
