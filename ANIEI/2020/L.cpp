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
    vector<string> comb(15, "9");
    comb[0] = "1";
    comb[1] = "1";
    comb[2] = "2";
    comb[3] = "2";
    comb[4] = "2";
    comb[5] = "6";
    comb[6] = "8";
    comb[7] = "10";
    comb[8] = "18";
    comb[9] = "20";
    comb[10] = "20";
    comb[11] = "28";
    comb[12] = "68";
    comb[13] = "88";

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        if (n < 14)
        {
            cout << comb[n] << ENDL;
        }
        else
        {
            lli ochos = n / 7 - 1;
            lli res = n - ochos * 7;
            cout << comb[res];
            FOR(i, 0, ochos)
            cout << "8";
            cout << ENDL;
        }
    }

    return 0;
}