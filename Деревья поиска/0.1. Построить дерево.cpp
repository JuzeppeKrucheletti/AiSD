#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/// 
/// ////////
/// 
struct tree
{
    int field;
    struct tree* left;
    struct tree* right;
};

void recLeftPreOrder(tree* node) {
    //act
    cout << node->field << endl;
    if (node->left != NULL) recLeftPreOrder(node->left);
    if (node->right != NULL) recLeftPreOrder(node->right);
}
void recRightPreOrder(tree* node) {
    //act
    if (node->right != NULL) recRightPreOrder(node->right);
    if (node->left != NULL) recRightPreOrder(node->left);
}
void recLeftInOrder(tree* node) {
    if (node->left != NULL) recLeftInOrder(node->left);
    //act
    if (node->right != NULL) recLeftInOrder(node->right);
}
void recRightInOrder(tree* node) {
    if (node->left != NULL) recRightInOrder(node->left);
    //act
    if (node->right != NULL) recRightInOrder(node->right);
}
void recLeftPostOrder(tree* node) {
    if (left != NULL) recLeftPostOrder(node->left);
    if (right != NULL) recLeftPostOrder(node->right);
    //act
}
void recRightPostOrder(tree* node) {
    if (left != NULL) recRightPostOrder(node->right);
    if (right != NULL) recRightPostOrder(node->left);
    //act
}

struct tree* AddNode(int x, tree* root) {
    if (!root)
    { // Если дерева нет, то формируем корень
        root = new tree; // память под узел
        root->field = x;   // поле данных
        root->left = NULL;
        root->right = NULL; // ветви инициализируем пустотой
    }
    else  if (x < root->field)   // условие добавление левого потомка
        root->left = AddNode(x, root->left);
    else if (x > root->field)    // условие добавление правого потомка
        root->right = AddNode(x, root->right);
    else return root;
    return root;
}


//string Left(tree* node, string str = "") {
//    //act
//    char* intStr = new char;
//    intStr = _itoa(node->field, intStr, 10);
//    string str1 = string(intStr);
//    str1 += "\n";
//    str += str1;
//    if (node->left != NULL) str = Left(node->left, str);
//    if (node->right != NULL) str = Left(node->right, str);
//    return str;
//}
void Left(tree* node,  ofstream& fout, bool b = true) {
    //act
    if (b)
        fout << node->field;
    else
        fout <<endl<< node->field;
    if (node->left != NULL) Left(node->left, fout, false);
    if (node->right != NULL)Left(node->right,fout,false);
   
}
///////////////////
//////////////
////////////////////////




ifstream fin;
ofstream fout;
int main()
{
    setlocale(LC_ALL, "ru");
    tree* T = nullptr;
    fin.open("input.txt");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
    string str;
    int x;

    while (!fin.eof())
    {
        fin >> str;
        x = stoi(str);
        T = AddNode(x, T);
    }
    fin.close();

    
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
   
    //string rez = Left(T);
    //rez = rez.substr(0, rez.length() - 1);
    //fout << rez;
    Left(T, fout);

    fout.close();
}