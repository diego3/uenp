#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

vector<string> openFile(const char* fileName);
void recordText(const char *fileName);
void encodeText(const char *fileName);
void decodeText(const char *fileName);
void printText(const char *fileName);



//test functions
void testOpenAndIterateOverAnFile() {
    vector<string> lines = openFile("testList.txt");
    for(unsigned int i = 0; i < lines.size(); i++){
        cout << "linha = " << lines[i] << endl;
    }
}


#endif // TESTS_H_INCLUDED
