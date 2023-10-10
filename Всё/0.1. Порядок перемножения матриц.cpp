#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace std;
struct matr {
    long n;
    long m;
};
long Matr(matr *mass, long size) {
    long** F = new long*[size];
    for (int i = 0; i < size; i++) {
        F[i] = new long[size];
    }
    for (int i = 0; i < size; i++) {
        F[i][i] = 0;
    }
    for (int i = 0; i < size-1; i++) {
        F[i][i+1] = mass[i].n*mass[i].m*mass[i+1].m;
    }
    for (int l = 1; l < size; ++l) {
        for (int i = 0; i < size - l; ++i) {
            int j = i + l;
            F[i][j] = LONG_MAX;
            for (int k = i; k < j; ++k) {
                long e = F[i][k] + F[k + 1][j] + (mass[i].n * mass[k].m * mass[j].m);
                if (F[i][j] > e) F[i][j] = e;
            }
        }
    }
    return F[0][size - 1];
}
ifstream fin;
ofstream fout;
int main()
{
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
    long size;
    fin >> size;
    matr* mass = new matr[size];
    int i = 0;
    while (!fin.eof())
    {
        fin >> mass[i].n;
        fin >> mass[i].m;
        i++;
    }
    fin.close();
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    fout << Matr(mass, size);
    fout.close();
    return 0;
}