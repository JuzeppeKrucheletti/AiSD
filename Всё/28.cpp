#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

/// 
/// ////////
/// 
 int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
struct tree
{
    int field;
    int h;
    bool equal;
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
   /// act
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
    
}
void recRightPostOrder(tree* node) {
    if (left != NULL) recRightPostOrder(node->right);
    if (right != NULL) recRightPostOrder(node->left);
   
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
struct tree* FindMin(tree* root)
{
    if (root->left) return FindMin(root->left);
    else return root;

 }
 struct tree* DeleteNode(int x, tree* root) {
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
            int min = FindMin(root->right)->field;
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
void Height(tree* node);
int size_ = 0, iter = 0;
int * massiv;
void Height(tree* node) {
    if (node->left != NULL) Height(node->left);
    if (node->right != NULL)Height(node->right);
    node->equal = false;
    if (node->left != NULL && node->right != NULL) {
        if (node->left->h == node->right->h) {
            node->equal = true;
            size_++;
        }
        if (node->left->h > node->right->h)
            node->h = node->left->h + 1;
        else
            node->h = node->right->h + 1;
    }
    else if (node->left != NULL) {
        node->h = node->left->h + 1;
    }
    else if (node->right != NULL) {
        node->h = node->right->h + 1;
    }
    else if(node->left == NULL && node->right == NULL) {
        node->h = 0;
        node->equal = true;
        size_++;
    }
}
void HeightMass(tree* node) {
    if (node->left != NULL) HeightMass(node->left);
    if (node->right != NULL)HeightMass(node->right);
    if (node->equal == true) { 
        massiv[iter] = node->field;
        iter++;
    }
}
int Node_Height(const tree* root) {
    int l, r, h = 0;
    if (root != NULL) {
        l = Node_Height(root->left);
        r = Node_Height(root->right);
        if (l > r) h = l + 1;
        else h = r + 1;
    }
    return h;
}
ifstream fin;
ofstream fout;
int main()
{
    //setlocale(LC_ALL, "ru");
    tree* T = nullptr;
    fin.open("tst.in");
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        system("pause");
        return 0;
    }
    int field;
    while (!fin.eof())
    {
        fin >> field;
        T = AddNode(field, T);
    }

    fin.close();
    

    fout.open("tst.out");
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл output.txt" << endl;
        system("pause");
        return 0;
    }
    Height(T);
    if (size_ % 2 == 0) {
        LeftInFile(T, fout);
    }
    else {
        massiv = new int[size_];
        HeightMass(T);
        qsort(massiv, size_, sizeof(int), compare);
        
        T = DeleteNode(massiv[(size_ / 2)], T);
        LeftInFile(T, fout);
    }

    fout.close();
}