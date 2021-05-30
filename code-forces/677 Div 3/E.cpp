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

lli fact(lli n)
{
    lli res = 1;
    FOR(i, 1, n + 1)
    res *= i;
    return res;
}

int main()
{
    IO;
    lli n;
    cin >> n;
    cout << (fact(n) / ((fact(n / 2) * fact(n - n / 2)))) * fact(n / 2 - 1) * fact(n / 2 - 1) / 2 << ENDL;

    return 0;
}