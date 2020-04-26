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

#define INF (1e9 + 20)

int main()
{
  IO;
  int n, c;
  cin >> n >> c;
  vector<lli> bk(n);
  FOR(i, 0, n)
  cin >> bk[i];
  sort(ALL(bk));
  int total = 0;
  while (bk.size())
  {
    total++;
    lli res = c - bk[bk.size() - 1];
    bk.erase(bk.end() - 1);
    auto pos = upper_bound(bk.begin(), bk.end(), res);
    if (!(pos == bk.begin()))
    {
      bk.erase(pos - 1);
    }
  }
  cout << max(1, total) << ENDL;
  return 0;
}