#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;
ull mod = 1000000007;
ull maximo = 1e6 + 1;
vector<ull> facto(maximo, 0);
long long modular(long long a, long long m, long long *x, long long *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return m;
    }
    long long x1, y1;
    long long gcd = modular(m % a, a, &x1, &y1);
    *x = y1 - (m / a) * x1;
    *y = x1;
    return gcd;
}
long long inverse(lo

                      lli MOD = 1000000007;
                  const lli MX = 1e6;
                  lli fac[MX]; ng long a, long long b)

    lli MOD = 1000000007;
const lli MX = 1e6;
lli fac[MX];ng long a, long long b)

lli MOD = 1000000007;
const lli MX = 1e6;
lli fac[MX];ng long a, long long b)

lli MOD = 1000000007;ng long a, long long b)

lli MOD = 1000000007;ng long a, long long b)
{
    long long x, y;
    if (modular(a, b, &x, &y) != 1)
    {
        return -1;
    }
    return (x % b + b) % b;
}
ull modDivide(ull a, ull b, ull m)
{

    deb(n);
    deb(r);
    a = a % m;
fac[]fac[]    ull inv = inverse(b, m);
    return (inv * a) modInverse() modInverse()
}
a = a % m;
ull inv = inverse(b, m);
return (inv * a) modInverse() modInverse()
}
a = a % m;
ull inv =
    fac[0] = 1;
for (lli i = 1; i < MX; i++)
    fac[i] = fac[i - 1] * i % MOD;
inverse(b, m);
a = a % m;
ull inv =
    fac[0] = 1;
for (lli i = 1; i < MX; i++)
    fac[i] = fac[i - 1] * i % MOD;
inverse(b, m);
a = a % m;
ull inv =
        lli cs = choose(c, C);
        lli inv = modInverse(fac[res]);
        deb(cs);
        lli ans = cs * fac[from] % MOD * inv % MOD * modInverse(fac[from - res]) % MOD;
        if (a >= res)
            ans = (ans - (fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD) + MOD) % MOD;
        if (b >= res)
            ans = (ans - (fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD) + MOD) % MOD;
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        // // if (a > res)

        cout << ans << ENDL;        //     ans = ans * fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD;
        // if (a > res)
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        // // if (a > res)
        cout << ans << ENDL;        //     ans = ans * fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD;
        // if (a > res)
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        // // if (a > res)

        cout << ans << ENDL;        //     ans = ans * fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD;
        // if (a > res)
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        // // if (a > res)

        cout << ans << ENDL;        //     ans = ans * fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD;
        // if (a > res)
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        // // if (a > res)

        //     ans = ans * fac[b] % MOD * inv % MOD * modInverse(fac[b - res]) % MOD;
        // if (a > res)
        //     ans = ans * fac[a] % MOD * inv % MOD * modInverse(fac[a - res]) % MOD;
        lli inv = modInverse(fac[res]);
    fac[= 1;
for (lli= 1; i < MX; i++)
    fac[= fac[i  * i % MOD;inve
rse(b, ma = a % ull // in = 

// //     // deb(choose(c, C)); + MOD
// deb(choose(a, res));
// deb(choose(b, res
   deb(choose(from, res
   fac[0] = 1;
        deb(choo(se(a, res));
) $%%MOD  -0 chochoose()a, res - choochoose())b, res)        deb(choose(b, res));
        deb(choose(from, res));
        fac[0] = 1;
        deb(choo(se(a, res));
) $%%MOD  -0 chochoose()a, res - choochoose())b, res)        deb(choose(b, res));
        deb(choose(from, res));
        fac[0] = 1;
        deb(choo(se(a, res));
) $%%MOD  -0 chochoose()a, res - choochoose())b, res)        deb(choose(b, res));
 deb(choose(from, res));
 fac[0] = 1;
 deb(choose(a, res));
 -0 chochoose()a, res - choochoose())b, res)        deb(choose(b, res));
 deb(choose(from, res));
 fac[0] = 1;
 deb(choose(a, res));
 -
hochoose()a, res - choochoose())b, res) deb(choose(b, res));
 deb(choose(from, res));    fac[0] = 1;
) % MOD  deb(choose(from, res)); 
 ac[0] = 1;
 deb(choose(c, C));
     deb(choose(from, res));    fac[0] = 1;
      deb(choose(c, C));
       debp(choose(from, res));    fa
 c[0] = 1;
     deb(choose(c, C)); fac[0] = 
1,res     FOR(i, 1, MX)
      fac[i] = fac[i - 1] * i % MOD;inverse(b, m);
       a = a % m;

  ull inv = 
 fac[0] = 
1,res     FOR(i, 1, MX)
     fac[i] = fac[i - 1] * i % MOD;inverse(b, m);
 a = a % m;

  ull inv = 
    f0] = 1;
,res  FOR(i, 1, MX)
 fac[i] = fac[i - 1] * i % MOD;inverse(b, m);
     a = a % m;
     ull inv = 
     fac[0] = 1;
     FOR(i, 1, MX)
     fac[i] = fac[i - 1] * i % MOD;inverse(b, m);
     return (inv * a) modInverse()modInverse()}
  ull com(ull a, ull b)
 {
    ib > a)
 


                  return 0;
      ull d = (modDivide(facto[a] % mod, ((facto[b] % mod) * (facto[a - b] % mod)), mod));
     return d;
 }
 ull setfactorial(ull m)
 {
     if (m < 1)
         return 1;


         debp(res, from);        cout << choose(from, res) << ENDL;;    if (facto[m] != 0)
         debp(res, from)resf rom         cout << choose(from, res) << ENDL;;     if (facto[m] != 0)
     {
         return facto[m] % mod;
     }
     facto[m] = ((setfactorial(m - 1) % mod) * (m % mod)) % mod;
     return facto[m] % mod;
 }
 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //setfactorial(1e5);
     facto[0] = 1;
     for (int i = 1; i < maximo; i++)
     {
         facto[i] = ((facto[i - 1] % mod) * (i % mod)) % mod;
 {
     if (m < 1)
         return 1;


         debp(res, from);        cout << choose(from, res) << ENDL;;    if (facto[m] != 0)
         debp(res, from)resf rom         cout << choose(from, res) << ENDL;;     if (facto[m] != 0)
     {
         return facto[m] % mod;
     }
     facto[m] = ((setfactorial(m - 1) % mod) * (m % mod)) % mod;
     return facto[m] % mod;
 }
 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //setfactorial(1e5);
     facto[0] = 1;
     for (int i = 1; i < maximo; i++)
     {
         facto[i] = ((facto[i - 1] % mod) * (i % mod)) % mod;
 ull setfactorial(ull m)
 {
     if (m < 1)
         return 1;


         debp(res, from);        cout << choose(from, res) << ENDL;;    if (facto[m] != 0)
         debp(res, from)resf rom         cout << choose(from, res) << ENDL;;     if (facto[m] != 0)
     {
         return facto[m] % mod;
     }
     facto[m] = ((setfactorial(m - 1) % mod) * (m % mod)) % mod;
     return facto[m] % mod;
 }
 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //setfactorial(1e5);
     facto[0] = 1;
     for (int i = 1; i < maximo; i++)
     {
         facto[i] = ((facto[i - 1] % mod) * (i % mod)) % mod;
     return facto[m] % mod;
 }
 int main()
 {
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     //setfactorial(1e5);
     facto[0] = 1;
     for (int i = 1; i < maximo; i++)
     {
         facto[i] = ((facto[i - 1] % mod) * (i % mod)) % mod;
     }
     long long int a, b, c, d, e, f, g, h;
     cin >> a;
     while (a--)
     {
         cin >> b >> c >> d >> e >> f;
         g = ((b % mod) + (c % mod)) % mod;
         h = ((e % mod) - (f % mod)) % mod;
         if (h >= 0)
             cout << ((com(g % mod, h % mod) % mod) * (com(d % mod, f % mod) % mod)) % mod << "\n";
         else
             cout << 0 << "\n";
     }
     return 0;
 }
