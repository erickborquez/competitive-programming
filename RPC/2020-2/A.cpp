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
#define INF 1000000000
using namespace std;

int main()
{
  IO;
  int s, c;

  cin >> s;
  vector<map<int, int>> best(s);
  int f, s;
  cin >> f >> s;
  best[0][f] = s;
  FOR(i, 1, s)
  {
    cin >> f >> s;
    best[i] = best[i - 1];
    best[i][f] = min(best[i - 1][f], s);
  }

  cin >> c;
  vector<pii> coins(c);
  FOR(i, 0, c)
  {
    cin >> coins[i].F >> coins[i].S;
  }

  sort(ALL(coins));
  lli total = 0;

  FOR(i, 0, s)
  {
    pii coin = coins[i];
    int pos = 0;
    for (int acc = s; acc > 0; acc /= 2)
    {
      if (best[pos + acc][coin.F]
    }
  }
  cout << total << ENDL;
  return 0;
}