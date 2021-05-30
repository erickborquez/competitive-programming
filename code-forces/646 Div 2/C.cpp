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
    // if (tc == 5)
    //   cout << "Here" << ENDL;
    int n, x;
    cin >> n >> x;
    vector<vector<int>> t(n + 1);
    FOR(i, 0, n - 1)
    {
      int from, to;
      cin >> from >> to;
      t[from].pb(to);
      t[to].pb(from);
    }
    int adj = t[x].size();
    // int toRemove = n - adj - 1;
    // if (tc == 5)
    // {
    //   deb(adj);
    //   deb(toRemove);
    // }
    if (adj <= 1 || n % 2 == 0)
      cout << "Ayush" << ENDL;
    else
      cout << "Ashish" << ENDL;
  }
  return 0;
}