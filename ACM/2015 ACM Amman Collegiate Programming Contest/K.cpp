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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    FOR(i, 0, n)
    cin >> v[i];
    sort(ALL(v));
    bool ok = false;
    FOR(i, 0, (n - 1))
    {
      if (v[i] > k)
        break;
      if (v[i] == 0)
        continue;
      if (k % v[i] == 0)
      {
        if (binary_search(v.begin() + i + 1, v.end(), k / v[i]))
        {
          ok = true;
          cout << v[i] << " " << k / v[i] << ENDL;
          break;
        }
      }
    }
    if (!ok)
      cout << -1 << ENDL;
  }
  return 0;
}
