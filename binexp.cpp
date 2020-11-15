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

lli MOD = 10;

lli binExp(lli u, lli v)
{
    if (v == 0)
        return 1;
    lli val = binExp(u, v / 2);
    if (v % 2)
    {
        return ((val * val) % MOD * u) % MOD;
    }
    return (val * val) % MOD;
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        lli a, b;
        cin >> a >> b;
        cout << binExp(a, b) << ENDL;
    }

    return 0;
}