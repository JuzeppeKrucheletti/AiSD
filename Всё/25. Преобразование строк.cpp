#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma
using namespace std;
int L(const char* A, const char* B, int size1, int size2, int x, int y, int z) {
    size1 += 1;
    size2 += 1;
    int** F = new int* [size1];
    for (int i = 0; i < size1; i++) {
        F[i] = new int[size2];
    }
    for (int i = 0; i < size1; i++) {
        F[i][0] = x*i;
    }
    for (int i = 0; i < size2; i++) {
        F[0][i] = y*i;
    }
    for (int i = 1; i < size1; i++) {
        for (int j = 1; j < size2; j++) {
            int delta;
            if (A[i - 1] == B[j - 1])
                delta = 0;
            else
                delta = 1;
            int min1 = F[i - 1][j] + x;
            if (F[i][j - 1] + y < min1) min1 = F[i][j - 1] + y;
            if (F[i - 1][j - 1] + delta * min(z, (x + y)) < min1) min1 = F[i - 1][j - 1] + delta * min(z, (x + y));
            F[i][j] = min1;
           // F[i][j] = min(F[i - 1][j] + x,F[i][j - 1] + y,F[i - 1][j - 1] + delta * min(z,(x + y)));
        }
    }
    return F[size1 - 1][size2 - 1];
}

ifstream fin;
ofstream fout;
int main()
{
    fin.open("in.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
    string str1, str2;
    int x, y, z;
    fin >> x >> y >> z;
    fin >> str1 >> str2;
    const char* A = new char[str1.length()];
    const char* B = new char[str2.length()];
    A = str1.c_str();
    B = str2.c_str();
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << A << endl << B;
    fin.close();
    fout.open("out.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    fout << L(A, B, str1.length(), str2.length(), x, y, z);
    fout.close();
    return 0;
}