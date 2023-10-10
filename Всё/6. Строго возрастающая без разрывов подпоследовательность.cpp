#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#pragma
using namespace std;
//int compare(const void* x1, const void* x2)
//{
//    return int(*(int*)x1 - *(int*)x2);
//}
/*
int compare(const void* x1, const void* x2)
{
    return int(*(int*)x1 - *(int*)x2);
}
int NOP(int* mass1, int* mass2, int size1, int size2) {
    size1 += 1;
    size2 += 1;
    int** F = new int*[size1];
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
            if (mass1[i-1] == mass2[j-1])
                F[i][j] = F[i - 1][j - 1] + 1;
            else
                F[i][j] = max(F[i][j - 1], F[i - 1][j]);
        }
    }
    return F[size1 - 1][size2 - 1];
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
    int size;
    fin >> size;
    int* mass = new int[size];
    int* mass_sort = new int[size];
    int* mass_sort_2 = new int[size];
    int k = 0;
    int e;
    while (k<size)
    {
        fin >> e;
        mass[k] = e;
        mass_sort[k] = e;
        k++;
    }
    qsort(mass_sort, size, sizeof(int), compare);
    int size2 = 1;
    mass_sort_2[0] = mass_sort[0];

    for (int i = 1; i < size; i++) {
        if (mass_sort[i] != mass_sort[i-1]) {
            mass_sort_2[size2] = mass_sort[i];
            size2++;
        }
    }
    fin.close();
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    fout << NOP(mass, mass_sort_2, size, size2);
    fout.close();
    delete[] mass, mass_sort, mass_sort_2;
    return 0;
}
*/

int indBin(int* P,int left,int right,int key) 
{
    int mid = 0;
    int ind = 0;
    bool indFound = false;
    for (mid = (left + right) / 2; left <= right && !indFound; mid = (left + right)/2) 
    {
        if (P[mid] > key) 
        {
            right = mid - 1;
        }
        else if (P[mid] == key) 
        {
            ind = mid;
            indFound = true;
        }
        else if (mid + 1 <= right && P[mid + 1] >= key) 
        {
            P[mid + 1] = key;
            ind = mid + 1;
            indFound = true;
        }
        else 
        {
            left = mid + 1;
        }
    }
    if (!indFound) 
    {
        if (mid == left) 
        {
            P[mid] = key;
            ind = mid;
        }
        else 
        {
            P[mid + 1] = key;
            ind = mid + 1;
        }
    }
    return ind;
}

int NVP(int *numbers, int size) 
{
    if (size <= 1) 
    {
        return 1;
    }

    int len = -1;

    int *P = new int[size];
    int *indexes = new int[size];

    for (int i = 0; i < size; ++i) 
    {
        P[i] = INT_MAX;
        P[i] = INT_MAX;
    }

    P[0] = numbers[0];
    indexes[0] = 0;

    for (int i = 1; i < size; ++i) 
    {
        indexes[i] = indBin(P, 0, i, numbers[i]);

        if (len < indexes[i]) 
        {
            len = indexes[i];
        }
    }
    return len + 1;
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
    int size;
    fin >> size;
    int* mass = new int[size];
    int k = 0;
    while (k < size)
    {
        fin >> mass[k];
        k++;
    }
    fin.close();
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    fout << NVP(mass,  size);
    fout.close();
    return 0;
}