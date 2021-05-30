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
int n, m;
int movesX[4] = {0, 1, 0, -1};
int movesY[4] = {-1, 0, 1, 0};
vector<string> v;
vector<vector<bool>> visited, dp;

bool isValid(int i, int j)
{
  return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int y, int x)
{
  if (visited[y][x])
    return;
  // debp(y, x);
  if (v[y][x] == '#')
    return;
  dp[y][x] = true;
  visited[y][x] = true;
  FOR(i, 0, 4)
  {
    int newY = y + movesY[i];
    int newX = x + movesX[i];
    if (isValid(newY, newX) && v[newY][newX] != '#' && !visited[newY][newX])
    {
      dfs(newY, newX);
    }
  }
}

int main()
{
  IO;
  int tc;
  cin >> tc;
  while (tc--)
  {
    cin >> n >> m;
    v = vector<string>(n);
    dp = vector<vector<bool>>(n, vector<bool>(m, false));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    dp[n - 1][m - 1] = 1;
    vector<pii>
        bad, good;
    FOR(i, 0, n)
    {
      cin >> v[i];
      FOR(j, 0, v[i].size())
      {
        if (v[i][j] == 'G')
          good.pb({i, j});
        if (v[i][j] == 'B')
          bad.pb({i, j});
      }
    }
    bool ok = true;
    for (auto u : bad)
    {

      FOR(i, 0, 4)
      {
        int newY = u.F + movesY[i];
        int newX = u.S + movesX[i];
        if (isValid(newY, newX))
        {
          if (v[newY][newX] == 'G')
          {
            // deb("???");
            ok = false;
            break;
          }
          if (v[newY][newX] == '.')
            v[newY][newX] = '#';
        }
      }
    }
    // FOR(i, 0, n)
    // {
    //   FOR(j, 0, m)
    //   {
    //     cout << v[i][j];
    //   }
    //   cout << ENDL;
    // }

    dfs(n - 1, m - 1);
    if (ok)
      for (auto u : good)
      {
        if (!dp[u.F][u.S])
        {
          // deb("???");
          ok = false;
          break;
        }
      }
    if (ok)
      cout << "Yes" << ENDL;
    else
      cout << "No" << ENDL;
  }
  return 0;
}