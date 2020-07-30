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
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  FOR(i, 0, n)
  {
    cin >> v[i];
  }
  int ans = 0;
  FOR(i, 0, n)
  {
    FOR(j, i + 1, n)
    {
      if ((v[j] - v[j - 1]) <= x)
        ans = max(ans, j - i);
      else
      {
        i = j - 1;
        break;
      }
    }
  }
  cout << ans + 1 << ENDL;
  return 0;
}