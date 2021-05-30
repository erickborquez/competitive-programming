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

int main()
{
    IO;
    vector<int> v(18);
    FOR(i, 0, 18)
    {
        cin >> v[i];
    }
    lli total = 0;
    cin.ignore();

    FOR(i, 0, 18)
    {
        string u;
        getline(cin, u);
        if (u == "hole in one")
        {
            total++;
        }
        else if (u == "condor")
        {
            total += v[i] - 4;
        }
        else if (u == "albatross")
        {
            total += v[i] - 3;
        }
        else if (u == "eagle")
        {
            total += v[i] - 2;
        }
        else if (u == "birdie")
        {
            total += v[i] - 1;
        }
        else if (u == "par")
        {
            total += v[i];
        }
        else if (u == "bogey")
        {
            total += v[i] + 1;
        }
        else if (u == "double bogey")
        {
            total += v[i] + 2;
        }
        else if (u == "triple bogey")
        {
            total += v[i] + 3;
        }
    }
    cout << total << ENDL;
    return 0;
}