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
    long field;
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

struct tree* AddNode(long x, tree* root) {
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
struct tree* FindMin(tree* root)
{
    if (root->left) return FindMin(root->left);
    else return root;

 }
 struct tree* DeleteNode(long x, tree* root) {
    if (!root)
    {
        return root;
    }
    else  if (x < root->field)
    {
        root->left = DeleteNode(x, root->left);
        return root;
    }
    else if (x > root->field)
    {
        root->right = DeleteNode(x, root->right);
        return root;
    }
    else if (x == root->field) 
    {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        else {
            long min = FindMin(root->right)->field;
            root->field = min;
            root->right = DeleteNode(min, root->right);
        }
    }
    return root;
}

 void LeftInFile(tree* node, ofstream& fout, bool b = true) {
     //act
     if (b)
         fout << node->field;
     else
         fout << endl << node->field;
     if (node->left != NULL) LeftInFile(node->left, fout, false);
     if (node->right != NULL)LeftInFile(node->right, fout, false);

 }
///////////////////
//////////////
////////////////////////




ifstream fin;
ofstream fout;
long main()
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
    long x, del_el;
    fin >> del_el;
    fin.ignore();
    while (!fin.eof())
    {
        fin >> str;
        x = stoi(str);
        T = AddNode(x, T);
    }
    fin.close();
    T = DeleteNode(del_el, T);
    fout.open("output.txt");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    LeftInFile(T, fout);
    fout.close();
}