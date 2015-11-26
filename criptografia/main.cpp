#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <tests.h>

using namespace std;

#define HANDLED_FILE "message.txt"

struct Encoder {


};

int main() {
    int menuOption = 0;

    while(menuOption != 5) {
        printf("1 - Gravar texto\n\
2 - Codificar texto\n\
3 - Decodificar texto\n\
4 - Exibir texto\n\
5 - Sair\n");

        cout << "digite uma opcao: ";
        cin.clear();
        cin >> menuOption;

        switch(menuOption){
            case 1:
                recordText(HANDLED_FILE);
                break;
            case 2:
                encodeText(HANDLED_FILE);
                break;
            case 3:
                decodeText(HANDLED_FILE);
                break;
            case 4:
                printText(HANDLED_FILE);
                break;
        }
    }

    return 0;
}


void recordText(const char *fileName) {
    string message;
    cout  << "entre com a mensagem a ser criptografada:";

    cin.ignore();
    getline(cin, message);

    ofstream textFile;
    textFile.open(fileName, ios::trunc | ios::out);
    textFile << message;
    textFile.flush();
    textFile.close();
}

void encodeText(const char *fileName) {
    int middle = 0;
    vector<string> message = openFile(fileName);


    ofstream file;
    file.open(fileName, ios::trunc | ios::out);


    file.close();
}

void decodeText(const char *fileName) {


}

void printText(const char *fileName) {
    vector<string> f = openFile(fileName);
    for(unsigned int i = 0; i < f.size(); i++){
        cout << f[i] << endl;
    }
}

vector<string> openFile(const char* fileName) {
    ifstream file;
    file.open(fileName);

    vector<string> lines;
    string line;
    while(file.good()) {
        getline(file, line);
        lines.push_back(line);
    }

    file.close();
    return lines;
}


