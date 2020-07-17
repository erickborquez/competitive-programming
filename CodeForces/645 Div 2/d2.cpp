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
lli sum(lli n)
{
  if (n % 2)
    return ((n + 1) / 2) * n;
  return (n / 2) * (n + 1);
}
int main()
{
  IO;
  lli n, x;
  cin >> n >> x;
  vector<lli> v(n * 2);
  lli ans = 0;
  FOR(i, 0, n)
  {
    cin >> v[i];
    v[n + i] = v[i];
    ans = max(ans, v[i]);
  }

  if (ans >= x)
  {
    cout << sum(ans) - sum(ans - x) << ENDL;
    return 0;
  }
  lli left = 0, right = 1, d = v[0], exDays = 0, exSum = 0;
  ans = sum(v[0]);
  lli last = ans;
  while (right < n * 2)
  {
    d += v[right];
    last += sum(v[right]);
    while (d > x)
    {
      d -= v[left];
      last -= sum(v[left]);
      left++;
    }
    exDays = x - d;
    if (left > 0 && exDays > 0)
    {
      exSum = sum(v[left - 1]) - sum(v[left - 1] - exDays);
      last += exSum;
    }
    right++;
    ans = max(last, ans);
    last = last - exSum;
    exSum = 0;
  }
  cout << ans << ENDL;

  return 0;
}