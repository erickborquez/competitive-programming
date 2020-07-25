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
#define FORN(i, a, n) for (int i = (a - 1); i >= (n); --i)
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
    int n, m;
    cin >> n >> m;
    vector<pii> dist(n + m, {0, 0});
    FOR(i, 0, n)
    {
      FOR(j, 0, m)
      {
        int u;
        cin >> u;
        if (u == 1)
          dist[i + j].F++;
        else
          dist[i + j].S++;
      }
    }
    int total = 0;
    // FOR(i, 0, n + m - 1)
    // {
    //   deb(i);
    //   debp(dist[i].F, dist[i].S);
    // }
    FOR(i, 0, (n + m) / 2 - 1 + (n + m) % 2)
    {
      int left = i, right = n + m - i - 2;
      // deb(i);
      // deba("ones", dist[left].F + dist[right].F);
      // deba("zeros", dist[left].S + dist[right].S);
      total += min(dist[left].F + dist[right].F, dist[left].S + dist[right].S);
    }
    cout << total << ENDL;
  }
  return 0;
}