#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    vector<bool> r(n, true), c(m, true);
    FOR(i, 0, n)
    {
      FOR(j, 0, m)
      {
        int u;
        cin >> u;
        if (u == 1)
        {
          r[i] = false;
          c[j] = false;
        }
      }
    }
    int rows = 0, columns = 0;
    for (auto u : r)
      if (u)
        rows++;
    for (auto u : c)
      if (u)
        columns++;
    // deb(rows);
    // deb(columns);
    if (min(rows, columns) % 2 == 0)
      cout << "Vivek" << ENDL;
    else
      cout << "Ashish" << ENDL;
  }
  return 0;
}