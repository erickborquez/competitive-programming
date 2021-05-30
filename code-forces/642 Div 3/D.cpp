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

class compare
{
public:
  bool operator()(pii a, pii b)
  {
    if (a.S - a.F == b.S - b.F)
      return a.F > b.F;
    return a.S - a.F < b.S - b.F;
  }
};

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, compare> dfs;
    dfs.emplace(make_pair(1, n));
    vector<int> res(n + 1);
    int cnt = 1;
    while (!dfs.empty())
    {
      pii range = dfs.top();
      dfs.pop();
      if (range.F > range.S)
        continue;
      // debp(range.F, range.S);
      int pos;
      pos = (range.F + range.S - (range.F + range.S) % 2) / 2;
      res[pos] = cnt++;
      // deb(pos - range.F);
      if (range.F != range.S)
      {
        int sizeLeft = range.S - pos;
        int sizeRight = pos - range.F;

        dfs.emplace(make_pair(pos + 1, range.S));
        dfs.emplace(make_pair(range.F, pos - 1));
      }
    }
    FOR(i, 1, n + 1)
    cout << res[i] << " ";
    cout << ENDL;
  }
  return 0;
}