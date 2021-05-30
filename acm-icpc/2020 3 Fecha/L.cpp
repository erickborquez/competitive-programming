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

string shift(string s)
{
    return s[s.size() - 1] + s.substr(0, s.size() - 1);
}

int main()
{
    IO;
    int n;
    cin >> n;
    int ans = 0;
    set<string> gen;
    FOR(i, 0, n)
    {
        string s;
        cin >> s;
        if (gen.count(s) > 0)
            continue;
        ans++;
        FOR(i, 0, s.size())
        {
            gen.emplace(s);
            s = shift(s);
        }
    }
    cout << ans << ENDL;

    return 0;
}