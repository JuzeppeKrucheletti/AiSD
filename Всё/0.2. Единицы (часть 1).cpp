#include <iostream>
using namespace std;

 long C(int n, int k)
{
    long mod = 1000000007;
    long **C = new long* [3];
    for (int i = 0; i < 3; i++) {
        C[i] = new long[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        C[i % 3][0] = 1;
        C[i % 3][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C[i % 3][j] = (C[(i - 1) % 3][j - 1] + C[(i - 1) % 3][j]) % mod;           
        }
    }
    return C[n % 3][k];
}
int main()
{
    long n,k;
    cin >> n >> k;
    cout << C(n, k);
    return 0;
}