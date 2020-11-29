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

const lli MX = 2 * 1e6;
vector<lli> primes;
bool isPrime[MX];
void criba()
{
    primes.pb(2);
    FOR(i, 0, MX)
    isPrime[i] = true;

    for (lli i = 3; i < MX; i += 2)
    {
        if (isPrime[i])
        {
            primes.pb(i);
            for (lli j = i; j * i < MX; j++)
            {
                isPrime[j * i] = false;
            }
        }
    }
}

int main()
{
    IO;
    criba();
    lli n, m;
    cin >> n >> m;
    vector<pair<lli, lli>> div;

    for (auto p : primes)
    {
        if (m == 1)
            break;
        if (m % p != 0)
            continue;

        lli times = 0;
        while (m % p == 0 && m > 1)
        {
            times++;
            m /= p;
        }
        div.pb({p, times});
    }
    if (m > 1)
    {
        div.pb({m, 1});
    }
    lli ans = 1;
    for (auto e : div)
    {
        FOR(i, 0, e.S / n)
        {
            ans *= e.F;
        }
    }

    cout << ans << ENDL;

    return 0;
}