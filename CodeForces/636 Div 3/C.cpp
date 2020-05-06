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
#define INF -2000000000
using namespace std;

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<lli> v(n);
    FOR(i, 0, n)
    {
      cin >> v[i];
    }
    bool pos = v[0] > 0;
    lli best = INF;
    lli total = 0;
    FOR(i, 0, n)
    {
      if (pos && v[i] < 0)
      {
        pos = false;
        total += best;
        best = v[i];
        continue;
      }
      else if (!pos && v[i] > 0)
      {
        pos = true;
        total += best;
        best = v[i];
        continue;
      }
      best = max(best, v[i]);
    }
    total += best;
    cout << total << ENDL;
  }
  return 0;
}