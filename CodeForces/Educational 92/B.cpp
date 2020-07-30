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
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n);
    vector<int> acc(n);

    FOR(i, 0, n)
    {
      cin >> v[i];
      acc[i] = v[i];
      if (i > 0)
        acc[i] += acc[i - 1];
    }
    lli ans = acc[k];
    FOR(i, 1, k)
    {
      int last = k, zC = z;
      lli a = acc[k];
      while (zC > 0 && last > i)
      {
        a -= v[last];
        a += v[i - 1];
        zC--;
        last--;
        if (last > i)
        {
          a += v[i];
          a -= v[last];
          last--;
        }

        // if (a > ans)
        // {
        //   debp(i, zC);
        // }
        ans = max(ans, a);
      }
    }

    cout << ans << ENDL;
  }
  return 0;
}