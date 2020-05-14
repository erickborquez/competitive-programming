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

#define INF 1000000

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    string s;
    vector<vector<int>> ap(k);
    cin >> s;
    int total = 0;
    FOR(i, 0, n)
    {
      if (s[i] == '1')
      {
        int pos = i % k;
        ap[pos].pb(i);
        total++;
      }
    }
    int best = total;
    FOR(i, 0, k)
    {
      if (ap[i].size() == 0)
        continue;
      while (ap[i].size() > 0)
      {
        int last = ap[i].size() - 1;
        int dist = ap[i][last] - ap[i][0];
        int toLight = 0;
        if (!dist == 0)
        {
          toLight = dist / k + 1 - ap[i].size();
        }
        // deb(i);
        // deb(dist);
        // debp(toLight, toTurnOff);
        best = min(best, toLight + total - (int)ap[i].size());
        if (ap[i].size() == 1)
          break;
        int fromLeft = ap[i][last] - ap[i][1];
        int fromRight = ap[i][last - 1] - ap[i][0];
        if (fromLeft > fromRight)
          ap[i].erase(ap[i].begin());
        else
          ap[i].erase(--ap[i].end());
      }
    }
    cout << best << ENDL;
  }
  return 0;
}