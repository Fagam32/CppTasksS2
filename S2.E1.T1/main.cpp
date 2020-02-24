#include <iostream>
#include <fstream>

using namespace std;

/*
 * Print last N rows of text file.
 * N reads from keyboard;
 * File name reads from command line(if presents) otherwise reads from keyboard
 */
int main(int argc, char **argv) {
    //Reading N and filename and open stream
    int N;
    cout << "Enter N" << endl;
    cin >> N;
    char *filename;
    if (argc == 2) {
        filename = argv[1];
    } else {
        char tmp[255];
        cout << "Enter filename" << endl;
        cin >> tmp;
        filename = tmp;
    }

    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        cout << "Troubles with file";
        return 0;
    }

    //counting numbers of rows
    char tmp[255];
    int rowNumber = 0;
    while (!file.eof()) {
        file.getline(tmp, 255, '\n');
        rowNumber++;
    }
    file.seekg(0, file.beg);

    if (N > rowNumber) {
        cout << "N is too big" << endl;
        return 0;
    }

    //Printing
    for (int i = 0; i < rowNumber; i++) {
        file.getline(tmp, 255, '\n');
        if (i >= rowNumber - N) {
            cout << tmp << endl;
        }
    }

    return 0;
}
