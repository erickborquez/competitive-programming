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
        int mx;
        cin >> mx;
        bool ok = false;
        bool right = false;
        int ptr = 0;
        FOR(i, 1, n)
        {
            int aux;
            cin >> aux;
            if (mx != aux)
                ok = true;
            if (aux > mx)
            {
                mx = aux;
                ptr = i;
                right = true;
            }
            else if (aux < mx && !right)
            {
                right = true;
                ptr = i - 1;
            }
        }
        if (ok)
            cout << ptr + 1 << ENDL;
        else
            cout << -1 << ENDL;
    }
    return 0;
}