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

int need(int h)
{
  int tr = (h * (h + 1)) / 2;
  return 3 * tr - h;
}

int main()
{
  IO;
  int t;
  cin >> t;

  while (t--)
  {
    int n, res = 0;
    cin >> n;
    while (n >= 2)
    {
      res++;
      int i = 1;
      int cards = need(i);
      while (true)
      {
        int next = need(++i);
        if (next > n)
          break;
        cards = next;
      }
      n -= cards;
    }
    cout << res << ENDL;
  }
  return 0;
}