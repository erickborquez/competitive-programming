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
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        map<int, int> gangs;
        FOR(i, 0, n)
        {
            int g;
            cin >> g;
            gangs[g]++;
        }
        bool ok = true;
        for (auto g : gangs)
        {
            if (g.S > (n / 2 + 1))
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "YES" << ENDL;
            for (auto u : gangs)
            {
                if (u.S == 0)
                    continue;
                for (auto v : gangs)
                {
                    if (u.F == v.F)
                        continue;
                    if (u.S == 0)
                        break;
                    if (v.S == 0)
                        continue;
                    cout << u.F << " " << v.F << ENDL;
                    gangs[u.F]--;
                    gangs[v.F]--;
                }
            }
        }
        else
            cout << "NO" << ENDL;
    }
    return 0;
}