#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// file won't open. Is it a windows/linux problem?
// cin getline problems


int main(int argc, char const* argv[]) {
    string file;
    vector<string> vec;
    string line;
    if (argc > 1) {
        file = argv[1];
        ifstream in;
        in.open(file);
        if (!in.is_open()) {
            cout << "Error: file could not be opened";
            exit(1);
        }
        while (getline(in, line)) {
            vec.push_back(line);
        }
    }
    else{
        while(getline(cin, line)){
            vec.push_back(line);
            getline(cin, line);
        }
    }


    for (int i = 1; i < vec.size(); i++) {
        int nextpos = i;
        string nextval = vec.at(nextpos);
        while (nextpos > 0 && nextval < vec.at(nextpos-1)){
            vec.at(nextpos) = vec.at(nextpos - 1);
            nextpos--;
        }
        vec.at(nextpos) = nextval;
    }
    for (string item: vec){
        cout << item << endl;
    }


    return 0;
}
