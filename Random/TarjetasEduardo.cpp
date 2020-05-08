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
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<pii> LCS(n);
  FOR(i, 0, n)
  cin >> nums[i];
  FOR(i, 0, n)
  {
    pii best = make_pair(0, i);
    FOR(j, 0, i)
    {
      if (nums[i] >= nums[j])
      {
        if (LCS[j].F > best.F)
        {
          best = make_pair(LCS[j].F, j);
        }
      }
    }
    LCS[i] = make_pair(best.F + 1, best.S);
  }
  pii best = make_pair(-1, -1);
  FOR(i, 0, n)
  {
    if (LCS[i].F > best.F)
    {
      best = LCS[i];
      best.S = i;
    }
  }
  vector<int> path;
  while (true)
  {
    path.pb(best.S);
    if (LCS[best.S].S == best.S)
      break;
    best = LCS[best.S];
  }
  reverse(ALL(path));
  cout << path.size() << ENDL;
  for (auto e : path)
    cout << e + 1 << ENDL;

  return 0;
}