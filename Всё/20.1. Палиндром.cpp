#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#pragma
using namespace std;
void NOP(const char* mass1, char* mass2, int size1, int size2, ofstream& os) {
    size1 += 1;
    size2 += 1;
    int** F = new int* [size1];
    for (int i = 0; i < size1; i++) {
        F[i] = new int[size2];
    }
    for (int i = 0; i < size1; i++) {
        F[i][0] = 0;
    }
    for (int i = 0; i < size2; i++) {
        F[0][i] = 0;
    }
    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            if (mass1[i - 1] == mass2[j - 1]) {
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else {
                if (F[i - 1][j] > F[i][j - 1]) F[i][j] = F[i - 1][j];
                else F[i][j] = F[i][j - 1];
            }
        }
    }
    os << F[size1 - 1][size2 - 1] << endl;
    /*for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << F[i][j] << " ";
        }
        cout << endl;
    }*/
   
    char* mass = new char[F[size1 - 1][size2 - 1]];
    int size = 0;
    int j = size2 - 1;
    for (int i = size1 - 1; i > 0; ) {
        if (j <= 0||i<=0) break;
        for (; j > 0; ) {
            if (mass1[i-1] == mass2[j-1]) {
                mass[size] = mass1[i-1];
                i--;
                j--;
                size++;
            }
            else {
                if (F[i][j] == F[i][j - 1]) j--;
                else i--;
            }
            if (j <= 0 || i <= 0) break;
        }
    }
    for (int i = 0; i < F[size1 - 1][size2 - 1]; i++) {
        os << mass[i];
    }
}

ifstream fin;
ofstream fout;
int main()
{
    fin.open("input.txt");
    string str;
    fin >> str;
    fin.close();
    const char* ch = str.c_str();
    char* ch_2 = new char[str.length()];
    for (int i = str.length() - 1, j = 0; i >= 0; i--, j++) {
        ch_2[i] = ch[j];
    }
    
    fout.open("output.txt");
    
    NOP(ch, ch_2, str.length(), str.length(), fout);
    fout.close();
    return 0;
}
