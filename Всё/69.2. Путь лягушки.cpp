#include <iostream>
using namespace std;
struct L {
    int com;
    int max;
};
L* Frosch(int n, L* F)
{
    F[0].max = F[0].com;
    F[1].max = -1;
    F[2].max = F[0].max + F[2].com;
    for (int i = 3, j = 1; i < n; i++) {
        if (F[i - 2].max > F[i - 3].max) {
            F[i].max = F[i - 2].max + F[i].com;
        }
        else {
            F[i].max = F[i - 3].max + F[i].com;
        }
    }

    return F;
}
int main()
{
    int n;
    cin >> n;
    L* F = new L[n];
    for (int i = 0; i < n; i++) {
        cin >> F[i].com;
    }
    if (n != 2) {
        if (n == 1) {
            cout << F[0].com << endl;
            cout << 1;
        }
        else if (n == 3)
        {
            cout << F[0].com + F[2].com << endl;
            cout << 1 << " " << 3;
        }
        else {
            F = Frosch(n, F);

            cout << F[n - 1].max << endl;
            int size = 0;
            int* mass = new int[n];
            for (int i = n - 1, j = 0; i > 0; j++) {
                if (F[i - 2].max == F[i].max - F[i].com) {
                    mass[j] = i - 1;
                    i = i - 2;

                }
                else {

                    mass[j] = i - 2;
                    i = i - 3;
                }
                size++;
            }
            for (int i = size - 1; i >= 0; i--) {
                cout << mass[i] << " ";
            }
            cout << n;
        }
    }
    else cout << -1;

    //6
     //   1 100 3 4 1000 0
    return 0;
}