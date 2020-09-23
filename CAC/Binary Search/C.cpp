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

lli INF = 2 * 1e9;

lli k;
vector<lli> nums;

bool ok(lli u)
{
  lli res = k;
  // deb(res);
  for (auto e : nums)
  {
    if (e < u)
    {
      res -= u - e;
      // deb(u);
      // debp(e, res);
      if (res < 0)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  IO;
  lli n;
  cin >> n >> k;
  vector<lli> v(n);
  FOR(i, 0, n)
  {
    cin >> v[i];
  }
  sort(ALL(v));
  FOR(i, n / 2, n)
  {
    nums.pb(v[i]);
  }
  lli ptr = 0;
  for (lli i = INF; i > 0; i /= 2)
  {
    while (ok(ptr + i))
      ptr += i;
  }
  cout << ptr << ENDL;
  return 0;
}