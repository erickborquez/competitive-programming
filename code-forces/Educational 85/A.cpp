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
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int p1 = 0, c1 = 0, p2, c2, difP, difC;
    bool ok = true;
    while (n--)
    {
      cin >> p2 >> c2;
      if (p1 > p2 || c1 > c2)
      {
        ok = false;
      }
      difP = p2 - p1;
      difC = c2 - c1;
      if (difC > difP)
      {
        ok = false;
      }
      p1 = p2;
      c1 = c2;
    }
    if (ok)
    {
      cout << "YES" << ENDL;
    }
    else
    {
      cout << "NO" << ENDL;
    }
  }

  return 0;
}