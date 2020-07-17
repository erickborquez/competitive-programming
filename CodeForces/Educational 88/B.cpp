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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    char last = '*';
    lli total = 0;
    y = min(2 * x, y);
    FOR(i, 0, n)
    {
      string s;
      cin >> s;
      FOR(j, 0, s.size())
      {
        if (s[j] == '.')
          if (last == '.')
          {
            total += y;
            last = '*';
          }
          else
            last = '.';
        else if (last == '.')
        {
          total += x;
          last = '*';
        }
        else
          last = '*';
      }
      if (last == '.')
        total += x;
      last = '*';
    }
    cout << total << ENDL;
  }

  return 0;
}