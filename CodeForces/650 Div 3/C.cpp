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
    string s;
    cin >> n >> k >> s;
    vector<int> vLeft(n), vRight(n);
    vLeft[0] = s[0] == '1' ? -1 : k;
    vRight[n - 1] = s[n - 1] == '1' ? -1 : k;
    FOR(i, 1, n)
    {
      if (s[i] == '1')
        vLeft[i] = -1;
      else
        vLeft[i] = vLeft[i - 1] + 1;

      // debp(i, vLeft[i]);
    }
    FORN(i, n - 1, 0)
    {
      if (s[i] == '1')
        vRight[i] = -1;
      else
        vRight[i] = vRight[i + 1] + 1;
      // debp(i, vRight[i]);
    }
    lli ans = 0;
    for (int i = 0; i < n; i++)
    {
      // deb(i);
      // debp(vLeft[i], vRight[i]);
      if (s[i] == '0' && vLeft[i] >= k && vRight[i] >= k)
      {
        // deba("ok", i);
        ans++;
        i += k;
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}