#include <iostream>
#include <fstream>

using namespace std;
ifstream fin;
ofstream fout;
bool IsBinRec(int* mass, int size, int i) {
	if (2 * i >= size) {
		return true;
	}
	else if (2 * i == size-1 && mass[i] <= mass[2 * i]) return true;
	else if (mass[i] <= mass[2 * i] && mass[i] <= mass[2 * i + 1] && IsBinRec(mass, size, 2 * i + 1) == true && IsBinRec(mass, size, 2 * i) == true) return true;
	else { return false;
	cout << mass[i] << endl << mass[2 * i] << endl << mass[2 * i + 1] << endl;
	}
}
//string IsBin(int* mass, int size) {
//	if (IsBinRec(mass, size, 0) == true) return "Yes";
//	else return "No";
//}



	 


int main()
{
	fin.open("input.txt");
	if (!fin.is_open())
	{
		cout << "Не удалось открыть файл input.txt" << endl;
		system("pause");
		return 0;
	}


	int n;
	fin >> n;
	n += 1;
	int* mass = new int[n];
	for (int i = 1; i < n; i++)
	{
		fin >> mass[i];
		//cout << mass[i] << " ";
	}
	//cout << endl << endl;
	fin.close();
	fout.open("output.txt");
	if (!fout.is_open())
	{
		cout << "Не удалось открыть файл output.txt" << endl;
		system("pause");
		return 0;
	}
	if (IsBinRec(mass, n, 1)==true) fout << "Yes";
	else fout << "No";
	fout.close();
	return 0;
}