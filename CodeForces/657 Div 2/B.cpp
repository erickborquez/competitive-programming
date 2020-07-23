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
    lli l, r, m, a, b, c;
    cin >> l >> r >> m;
    lli diff = r - l;
    if (l <= m)
    {

      FOR(i, 0, r - l + 1)
      {
        a = l + i;
        // deb(i);
        // deb(m % a);
        // deb(a - m % a);
        if (m % (a) <= diff)
        {
          b = l + m % a;
          c = l;
          break;
        }
        else if (a - (m % a) <= diff)
        {
          b = l;
          c = l + a - m % a;
          break;
        }
      }
    }
    else
    {
      a = l;
      b = l;
      c = a + b - m;
    }
    cout << a << " " << b << " " << c << ENDL;
  }
  return 0;
}