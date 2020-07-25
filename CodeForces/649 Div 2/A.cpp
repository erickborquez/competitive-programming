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
    int n, x;
    cin >> n >> x;
    vector<lli> acc(n + 1, 0), v(n + 1);
    int first = -1, last = -1;
    FOR(i, 1, n + 1)
    {
      cin >> v[i];
      acc[i] = v[i] + acc[i - 1];
      if (v[i] % x != 0)
      {
        last = i;
        first = first == -1 ? i : first;
      }
    }
    lli ans = -1;
    // debp(first, last);
    if (acc[n] % x != 0)
      ans = n;
    else if (acc[n] % x == 0 && first != -1)
    {
      int left = first;
      int right = n - last + 1;
      // deb(left);
      // deb(right);
      if (left > right)
        ans = n - right;
      else
        ans = n - left;
    }
    cout << ans << ENDL;
  }
  return 0;
}