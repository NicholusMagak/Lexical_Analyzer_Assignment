// Lexical_Analyzer
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
    char keywords[35][10] = { "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "include", "namespace", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "using", "void", "while" };

    int i, flag = 0;

    for (i = 0; i < 32; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}
int main()
{
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("text.txt");
    int i, j = 0;

    //check if the program is able to open the file
    if (!fin.is_open()) {
        cout << "error while opening the file \n";
        exit(0);
    }

    //while there is no more data available to read by the fstream from the .txt
    while (!fin.eof()) {
        ch = fin.get(); //loads all the available read data to ch

        //This looks for an operator by each character
        for (i = 0; i < 6; ++i) {
            if (ch == operators[i]) {
                cout << ch << " is operator \n";
            }
        }

        //Checks if a character is alphanumeric
        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == 1) {
                cout << buffer << " is keyword\n";
            }
            else {
                cout << buffer << " is identfier\n";
            }
        }
    }
    fin.close();

    return 0;
}

