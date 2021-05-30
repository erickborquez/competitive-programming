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
    vector<lli> num(n);
    vector<int> d(n, 0);
    FOR(i, 0, n)
    {
      cin >> num[i];
      num[i] += 2000000000LL;
    }
    lli mx = 0;

    FOR(i, 1, n)
    {
      lli diff = num[i - 1] - num[i];
      lli s = 1;
      if (diff > 0)
      {
        for (lli j = 0; j <= 70; j++)
        {
          if ((1LL << j) - 1 >= diff)
          {
            num[i] += diff;
            mx = max(mx, j);
            break;
          }
        }
      }
    }

    cout << mx << ENDL;
  }
  return 0;
}