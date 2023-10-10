#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma
using namespace std;

ifstream fin;
ofstream fout;
int main()
{
    int m, c, n;
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
    fin >> m >> c >>n;
    int* tablo = new int[m];
    
    for (int i = 0; i < m; i++) {
        tablo[i] = -1;
    }
    
    for (int j = 0; j < n; j++) {
        int x;
        fin >> x;
        int i = 0;
        int pos;
        while (true) {
            pos = ((x % m) + c * i) % m;
            if (tablo[pos] == -1|| tablo[pos] == x) {
                tablo[pos] = x;
                break;
            }
            else i++;
        }
    }
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    for (int i = 0; i < m; i++) {
        fout << tablo[i] << endl;
    }
    
    
    
    
    



    
    
    fin.close();
    fout.close();

    return 0;
}