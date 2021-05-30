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
#define INF 1000000
int main()
{
  IO;
  int n;
  cin >> n;
  bool ok = true;
  vector<int> ans(n, -1), v(n), disp;
  FOR(i, 0, n)
  cin >> v[i];
  FORN(i, n, 1)
  {
    if (v[i] > v[i - 1])
    {
      ans[i] = v[i - 1];
      FOR(j, v[i - 1] + 1, v[i])
      disp.pb(j);
    }
  }
  if (v[0] > 1)
    ok = false;
  else if (v[0] == 1)
    ans[0] = 0;
  int ptr = disp.size() - 1;
  // cout << "Disp" << ENDL;
  // for (auto e : disp)
  //   cout << e << " ";
  // cout << ENDL;
  FOR(i, 0, n)
  {
    if (ans[i] == -1)
    {
      if (ptr < 0)
        ans[i] = INF;
      else
      {
        ans[i] = disp[ptr];
        ptr--;
      }
    }
  }
  if (ptr >= 0)
    ok = false;
  if (ok)
  {
    for (auto e : ans)
      cout << e << " ";
    cout << ENDL;
  }
  else
  {
    cout << -1 << ENDL;
  }
  return 0;
}