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
    vector<pii> ans;
    int lastEven = -1, lastOdd = -1;
    int aux;
    FOR(i, 0, 2 * n)
    {
      cin >> aux;
      if (aux % 2)
        if (lastEven != -1)
        {

          ans.pb({lastEven, i});
          lastEven = -1;
        }
        else
          lastEven = i;
      else if (lastOdd != -1)
      {
        ans.pb({lastOdd, i});
        lastOdd = -1;
      }
      else
        lastOdd = i;
    }

    FOR(i, 0, n - 1)
    {
      cout << ans[i].F + 1 << " " << ans[i].S + 1 << ENDL;
    }
  }
  return 0;
}