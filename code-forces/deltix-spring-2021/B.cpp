#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
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
#define IO                          \
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
    cout << n / 2 * 6 << ENDL;
    for (int i = 1; i <= n; i += 2)
    {
      int a, b;
      cin >> a >> b;
      cout << 1 << " " << i << " " << i + 1 << ENDL;
      cout << 2 << " " << i << " " << i + 1 << ENDL;
      cout << 2 << " " << i << " " << i + 1 << ENDL;
      cout << 1 << " " << i << " " << i + 1 << ENDL;
      cout << 2 << " " << i << " " << i + 1 << ENDL;
      cout << 2 << " " << i << " " << i + 1 << ENDL;

      // 1 x + y, y
      // 2 x + y, -x
      // 2 x + y, -2x -y
      // 1 -x, -2x - y
      // 2 -x, -x - y
      // 2 -x, -y
    }
  }
  return 0;
}