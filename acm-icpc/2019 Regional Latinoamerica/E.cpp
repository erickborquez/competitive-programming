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
  string s;
  int n;
  cin >> s >> n;
  lli ans = 0;
  vector<int> v = {10000000};
  FOR(i, 0, s.size())
  {
    if (s[i] == 'E')
    {
      v.pb(i);
      v.pb(i + s.size());
    }
  }
  sort(ALL(v));
  FOR(i, 0, s.size())
  {
    if (s[i] == 'E')
      ans += n;
    else
    {
      int pos = *lower_bound(ALL(v), i);
      int aum = n - (pos - i);
      ans += max(0, aum);
    }
  }
  cout << ans << ENDL;
  return 0;
}