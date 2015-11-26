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

    string part1;
    string part2;
    int messageLen = 0;
    for(unsigned int i=0; i < message.size(); i++) {
        string aux = message[i];

        messageLen += aux.size();

        middle = aux.size()  / 2;
        for(unsigned int j = 0; j < aux.size(); j++) {
            //cout << aux[j] << "\n";
            if(j <= middle) {
                part1.push_back(aux[j]);
            }else {
                part2.push_back(aux[j]);
            }
        }
    }

    //cout << "part1 = " << part1 << " size = " << part1.size() << endl;
    //cout << "part2 = " << part2 << " size = " << part2.size() << endl;
    string cript;
    int a = 0;
    int b = 0;
    for(int j = 0; j < messageLen; j++) {//7,  0 1 2 3 4 5 6

        if( (j & 2) == 0) {
            cript.push_back(part1[a]);
            a++;
        }
        else {
            cript.push_back(part2[b]);
            b++;
        }
    }

    cout << "cript = " << cript << endl;

    /*
    ofstream file;
    file.open(fileName, ios::trunc | ios::out);


    file.close();*/
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


