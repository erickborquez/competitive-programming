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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), acc(n, 0);
    FOR(i, 0, n)
    cin >> v[i];
    FOR(i, 1, n - 1)
    {
      acc[i] = acc[i - 1];
      if (v[i] > v[i - 1] && v[i] > v[i + 1])
        acc[i]++;
    }
    // FOR(i, 0, n)
    // cout << acc[i] << ", ";
    // cout << ENDL;
    pii ans = {0, 0};
    FOR(i, 0, n - k + 1)
    {
      int val = acc[i + k - 2] - acc[i];
      // debp(i, val);
      if (ans.F < val)
        ans = {val, i};
    }
    cout << ans.F + 1 << " " << ans.S + 1 << ENDL;
  }
  return 0;
}