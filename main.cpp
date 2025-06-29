#include <fstream>
#include <string>
#include <iostream>
#include "Lexer.h"

using namespace std;

int main(int argc, char *argv[])
{
    read code;

    string name = argv[1];
    ifstream file(name);
    if (!file) {
        cerr << "Could not open file\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        code.decide(line);
    }

    file.close();

    return 0;
}