#include <iostream>
#include <fstream>

using namespace std;

/*
 * From file with C++ program read and print all function headers.
 * Nowhere but functions can use "{" "}"
 */

int main() {
    string filename;
    cout << "Enter filename" << endl;
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Troubles with file";
        return 0;
    }
    char *prevLine, *currLine = nullptr;
    while (!file.eof()) {
        prevLine = currLine;
        currLine = new char[1024];

        file.getline(currLine, 1024, '\n');

        /*
         * if code looks like:
         *  void functionName(int q)
         *  {
         *  //stuff
         *  }
         */
        if (currLine[0] == '{') {
            // printing function and skipping function body
            cout << prevLine << endl;
            bool flag = false;
            char tmp[1024];

            while (!file.eof() && !flag) {
                file.getline(tmp, 1024, '\n');
                for (char j : tmp) {
                    if (j == '}')
                        flag = true;
                }
            }
        } else {
            /*
             * if code looks like:
             * void foo() {
             * //bar
             * }
             */
            for (int i = 1; i < 1024; i++)
                if (currLine[i] == '{') {
                    cout << currLine << endl;
                    bool flag = false;
                    char tmp[1024];
                    while (!file.eof() && !flag) {
                        file.getline(tmp, 1024, '\n');
                        for (char j : tmp) {
                            if (j == '}') {
                                flag = true;
                                break;
                            }
                        }
                    }
                    break;
                }
        }
    }
    return 0;
}
