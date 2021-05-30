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

const int SIZE = 5 * 1e3;

vector<int> primes;
int isPrime[SIZE];

void criba()
{
    for (int i = 0; i < SIZE; i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < SIZE; i++)
    {
        if (isPrime[i])
        {
            primes.pb(i);
            for (int j = i; j * i < SIZE; j++)
            {
                isPrime[j * i] = false;
            }
        }
    }
}

int main()
{
    IO;
    int n;
    cin >> n;
    criba();
    while (n--)
    {
        set<int> sol;
        int a, b;
        cin >> a >> b;
        for (auto p : primes)
        {
            int sq = p * p;
            if (sq > a && sq > b)
                break;
            if (a % p == 0)
                sol.insert(p);
            else if (b % p == 0)
                sol.insert(p);

            while (a % p == 0)
                a /= p;
            while (b % p == 0)
                b /= p;
        }
        if (a > 1)
            sol.insert(a);
        if (b > 1)
            sol.insert(b);
        cout << sol.size() << ENDL;
    }
    return 0;
}