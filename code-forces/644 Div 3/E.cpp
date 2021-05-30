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
int n;

int movX[4] = {0, -1};
int movY[4] = {-1, 0};

bool isValidPos(pii pos)
{
  if (pos.F >= n || pos.F < 0 || pos.S >= n || pos.S < 0)
    return false;
  return true;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    vector<string> v(n);
    FOR(i, 0, n)
    cin >> v[i];
    queue<pii> bfs;
    FOR(i, 0, n)
    {
      if (v[i][n - 1] == '1')
        bfs.emplace(make_pair(i, n - 1));
      if (v[n - 1][i] == '1')
        bfs.emplace(make_pair(n - 1, i));
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false)),
        ans(n, vector<bool>(n, false));

    while (!bfs.empty())
    {

      pii pos = bfs.front();
      ans[pos.F][pos.S] = true;
      // debp(pos.F, pos.S);
      bfs.pop();
      if (!visited[pos.F][pos.S])
      {
        FOR(i, 0, 2)
        {
          pii newPos = pos;
          newPos.F += movY[i];
          newPos.S += movX[i];
          if (isValidPos(newPos) && v[newPos.F][newPos.S] == '1')
          {
            bfs.emplace(newPos);
          }
        }
      }
      visited[pos.F][pos.S] = true;
    }
    bool ok = true;
    FOR(i, 0, n)
    {
      FOR(j, 0, n)
      {
        // cout << ans[i][j] ? "1" : "0";
        if (v[i][j] == '1')
        {
          if (!ans[i][j])
          {
            ok = false;
            // break;
          }
        }
      }
      // cout << ENDL;
    }
    if (ok)
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }

  return 0;
}