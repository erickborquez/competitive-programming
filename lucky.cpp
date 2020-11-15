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

vector<lli> luckys;

const lli limit = 1e9;

void calc(lli u)
{
    if (u >= limit)
        return;
    luckys.push_back(u);
    calc(u * 10 + 4);
    calc(u * 10 + 7);
}

int main()
{
    IO;
    calc(4);
    calc(7);
    lli u;
    cin >> u;
    sort(ALL(luckys));
    int pos = lower_bound(luckys.begin(), luckys.end(), u) - luckys.begin() + 1;
    cout << pos << ENDL;

    return 0;
}