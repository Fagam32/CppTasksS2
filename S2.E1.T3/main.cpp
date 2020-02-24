#include <iostream>
#include <fstream>

using namespace std;

/*
 * Find the longest word in the text and count its appearances in the text
 */
int main() {
    cout << "Enter filename" << endl;
    string filename;
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Troubles with file";
        return 1;
    }
    string word = "", newWord;
    int count = 0;
    while (!file.eof()) {

        file >> newWord;
        if (newWord.length() > word.length()) {
            word = newWord;
            count = 1;
        } else if (newWord.compare(word) == 0)
            count++;
    }
    cout << word << " " << count;
    return 0;
}
