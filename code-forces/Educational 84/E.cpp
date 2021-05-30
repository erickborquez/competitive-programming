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

#define MOD 998244353
using namespace std;

lli POW[200005];

lli getBlocks(lli n, lli m)
{
  lli total = 0;
  if (n == m)
    return 10;
  total = ((9 * POW[n - m]) % MOD) * 2 % MOD;
  lli moves = n - m - 1;
  total = (total + 10 * (81 * (moves * POW[moves - 1] % MOD) % MOD) % MOD) % MOD;

  return total;
}

int main()
{
  IO;
  lli n;
  cin >> n;
  POW[0] = 1;
  FOR(i, 1, 200005)
  {
    POW[i] = (POW[i - 1] * 10) % MOD;
  }
  FOR(i, 1, n + 1)
  {
    cout << getBlocks(n, i) << " ";
  }

  return 0;
}