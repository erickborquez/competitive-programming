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

const lli MAX = 1e6;
bool isPrime[2 * MAX + 10];
map<string, lli> dp;
vector<lli> primes;

void criba()
{
    isPrime[0] = false;
    isPrime[1] = false;
    FOR(i, 2, MAX)
    isPrime[i] = true;
    primes.pb(2);

    for (lli i = 4; i <= MAX; i += 2)
        isPrime[i] = false;
    for (lli i = 3; i < MAX; i += 2)
    {
        if (isPrime[i])
        {
            primes.pb(i);
            for (lli j = i; j * i < MAX; j++)
            {
                isPrime[i * j] = false;
            }
        }
    }
}

bool testPrime(lli u)
{
    if (u >= MAX)
    {
        for (auto p : primes)
        {
            if (u % p == 0)
                return false;
        }
        return true;
    }
    else
        return isPrime[u];
}

int main()
{
    IO;
    criba();
    string s;
    cin >> s;
    lli n = s.size();
    lli sm = -1;

    sort(ALL(s));

    do
    {
        FOR(i, 1, n - 1)
        {
            if (s[0] == '0')
                continue;
            lli a = stol(s.substr(0, i));
            if (testPrime(a))
                FOR(j, 1, n - i)
                {
                    if (s[i] == '0')
                        continue;
                    if (s[i + j] == '0')
                        continue;
                    lli b = stol(s.substr(i, j));
                    lli c = stol(s.substr(i + j, n - i - j));
                    if (testPrime(b) && testPrime(c))
                    {
                        if (sm == -1)
                            sm = a * b * c;
                        else
                            sm = min(sm, a * b * c);
                    }
                }
        }
    } while (next_permutation(ALL(s)));

    if (sm != -1)
        cout << sm << ENDL;
    else
        cout << "Bob lies" << ENDL;

    return 0;
}