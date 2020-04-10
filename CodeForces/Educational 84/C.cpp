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
  int n, m, k;
  cin >> n >> m >> k;
  vector<pii> ini(k), to(k);
  FOR(i, 0, k)
  {
    cin >> ini[i].F >> ini[i].S;
  }
  FOR(i, 0, k)
  {
    cin >> ini[i].F >> ini[i].S;
  }
  int moves = n + m + n * m - 3;
  cout << moves << ENDL;
  FOR(i, 1, m)
  {
    cout << "L";
  }
  FOR(i, 1, n)
  {
    cout << "U";
  }
  FOR(i, 0, n)
  {
    if (i != 0)
      cout << "D";
    if (i % 2 == 0)
    {
      FOR(i, 1, m)
      {
        cout << "R";
      }
    }
    else
    {
      FOR(i, 1, m)
      {
        cout << "L";
      }
    }
  }
  cout << ENDL;
  return 0;
}