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
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> v(n), ans;
    FOR(i, 0, n)
    {
      cin >> v[i];
    }
    FOR(i, 0, n)
    {
      if (i == 0 || i == n - 1 || v[i] > v[i - 1] && v[i] > v[i + 1] || v[i] < v[i + 1] && v[i] < v[i - 1])
        ans.pb(v[i]);
    }
    cout << ans.size() << ENDL;
    for (auto e : ans)
    {
      cout << e << " ";
    }
    cout << ENDL;
  }

  return 0;
}