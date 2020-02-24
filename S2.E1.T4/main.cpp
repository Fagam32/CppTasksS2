#include <iostream>
#include <fstream>

using namespace std;
/*
 * Replace all quotes with << and >>
 */
int main(int argc, char** argv) {
    ifstream file(argv[1]);
    ofstream outfile(argv[2]);
    if (!file.is_open()) {
        cout << "Troubles with file";
        return 1;
    }

    char line[1024];
    bool open = true;
    while(!file.eof()){
        file.getline(line, 1024,'\n');
        string s = line;

        if (s[0] == '"'){
            if (open){
                s[0] = '<'; s.insert(0,"<");
                open = !open;
            } else {
                s[0] = '>'; s.insert(0,">");
                open = !open;

            }
        }

        for (int i = 0; i < s.length(); i++){
            if (s[i] == '"' && s[i - 1] != '\\'){
                if (open){
                    s[i] = '<'; s.insert(i,"<");
                    open = !open;
                } else {
                    s[i] = '>'; s.insert(i,">");
                    open = !open;
                }
            }
        }
        s = s + '\n';
        char array[s.length() + 1];
        for (int i = 0; i < s.length() + 1; i++)
            array[i] = s[i];
        outfile.write(array, s.length() + 1);
    }
    outfile.close();
    return 0;
}
