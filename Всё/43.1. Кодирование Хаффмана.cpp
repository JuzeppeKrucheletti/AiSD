#include <iostream>
#include <fstream>
#include<queue>
using namespace std;
ifstream fin;
ofstream fout;
int main()
{
	fin.open("huffman.in");
	if (!fin.is_open())
	{
		cout << "Не удалось открыть файл input.txt" << endl;
		system("pause");
		return 0;
	}
	priority_queue<long long, vector<long long>, greater<long long>> Q;
	int n;
	fin >> n;
	long long o;
	for (int i = 0; i < n; i++)
	{
		fin >> o;
		Q.push(o);
	}
	fin.close();
	long long S = 0;
	long long e1, e2;
	while (Q.size() > 1) {
		e1 = Q.top();
		Q.pop();
		e2 = Q.top();
		Q.pop();
		S += e1 + e2;
		Q.push(e1 + e2);
	}
	fout.open("huffman.out");
	if (!fout.is_open())
	{
		cout << "Не удалось открыть файл output.txt" << endl;
		system("pause");
		return 0;
	}
	fout << S;
	fout.close();
	return 0;
}