#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

const lli SIZE = 1e5;

vector<lli> primes;
lli isPrime[SIZE];

void criba()
{
    for (lli i = 3; i < SIZE; i += 2)
        isPrime[i] = true;
    isPrime[2] = true;
    for (lli i = 3; i < SIZE; i += 2)
    {
        if (isPrime[i])
        {
            primes.pb(i);
            for (lli j = i; j * i < SIZE; j += 2)
            {
                isPrime[j * i] = false;
            }
        }
    }
}

lli binPow(long long b, long long ex, long long MOD)
{
    if (b == 1)
        return 1;
    long long r = 1;
    while (ex)
    {
        if (ex & 1)
            r = (r * b) % MOD;
        ex = ex >> 1;
        b = (b * b) % MOD;
    }
    return r % MOD;
}

lli primeExp[SIZE];

int main()
{
    IO;
    criba();
    for (auto p : primes)
    {
        primeExp[p] = binPow(2, p, p);
    }

    lli t, k;
    cin >> t;
    while (t--)
    {
        cin >> k;
        vector<int> ans;
        for (auto p : primes)
        {
            if ((primeExp[p] + k) % p == 0)
                ans.pb(p);
        }
        if (ans.size() == 0)
        {
            cout << -1 << ENDL;
            continue;
        }
        for (auto p : ans)
            cout << p << " ";
        cout << ENDL;
    }

    return 0;
}