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
string repeat(char c, int k)
{
    string sol = "";
    FOR(i, 0, k)
    sol += c;
    return sol;
}

int main()
{
    IO;
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        lli k;
        cin >> s >> k;
        lli times = 0;
        bool ok = true;
        string ans = "";
        for (auto c : s)
        {
            if (c >= '0' && c <= '9')
            {
                times = times * 10 + c - '0';
                if (ans.size() + times > k)
                {
                    ok = false;
                    times = 0;
                    break;
                }
            }
            else
            {
                ans += repeat(c, max(1LL, times));
                times = 0;
            }
        }
        if (ok && ans.size() <= k)
        {
            cout << ans << ENDL;
        }
        else
        {
            cout << "unfeasible" << ENDL;
        }
    }

    return 0;
}