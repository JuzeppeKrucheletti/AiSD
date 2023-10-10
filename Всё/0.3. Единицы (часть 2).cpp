#include <iostream>
using namespace std;
long long mod = 1000000007;
 long long modbinpow(long long a, long long n) {
    long long res = 1;
    while (n)
        if (n%2==1) {
            res = (res*a)%mod;
            n--;
        }
        else {
            a = (a*a)%mod;
            n = n/2;
        }
    return res;
}
 long long C(long long n, long long k)
{
    long long C = 1;
    long long zn = 1;
    if (k > (n - k)) {
      
        for (long long i = k + 1; i <= n; i++) {
            
            C = (C * (i % mod))%mod;
        }
        
        for (long long i = 1; i <= n - k; i++)
        {
            zn = (zn * (i % mod)) % mod;
        }
       
        C = (C * modbinpow(zn, mod - 2)) % mod;
        
    }
    else {
        
        for (long long i = n - k + 1; i <= n; i++) {

            C = (C * (i % mod)) % mod;
        }
        
        for (long long i = 1; i <= k; i++)
        {
            zn = (zn * (i % mod)) % mod;
        }
        C = (C * modbinpow(zn, mod - 2)) % mod;
        
    }
    return C;
}
int main()
{
    long long n,k;
    cin >> n >> k;
    cout << C(n, k);
    return 0;
}