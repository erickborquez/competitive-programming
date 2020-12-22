#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
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

vector<string> mp;
vector<vector<bool>> visited;
vector<vector<int>> reach;
int n, m, d;
int mY[4] = {-1, 0, 1, 0};
int mX[4] = {0, 1, 0, -1};
pii s = {-1, -1}, f = {-1, -1};

bool isValid(int y, int x)
{
  return y >= 0 && y < n && x >= 0 && x < m;
}

int main()
{
  IO;
  cin >> n >> m >> d;
  reach.assign(n, vector<int>(m, -1));
  visited.assign(n, vector<bool>(m, false));
  vector<pii> mnt;
  queue<pii> mq;
  FOR(i, 0, n)
  {
    string st;
    cin >> st;
    FOR(j, 0, m)
    {
      if (st[j] == 'S')
        s = {i, j};
      else if (st[j] == 'F')
        f = {i, j};
      else if (st[j] == 'M')
        mq.push({i, j});
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int step = 0;
  while (d >= step && !mq.empty())
  {
    int sz = mq.size();
    while (sz--)
    {
      auto top = mq.front();
      mq.pop();
      int y = top.F, x = top.S;
      reach[y][x] = false;
      for (int i = 0; i < 4; i++)
      {
        int nY = y + mY[i], nX = x + mX[i];
        if (isValid(nY, nX) && !vis[nY][nX])
        {
          vis[nY][nX] = true;
          mq.push({nY, nX});
        }
      }
    }
    step++;
  }
  if (!reach[s.F][s.S] || !reach[f.F][f.S])
  {
    cout << -1 << ENDL;
    return 0;
  }

  queue<pii> q;
  q.push(s);
  int steps = 0;
  visited[s.F][s.S] = true;
  while (!q.empty())
  {
    int sz = q.size();
    while (sz--)
    {
      auto top = q.front();
      q.pop();
      if (top == f)
      {
        cout << steps << ENDL;
        return 0;
      }
      int y = top.F, x = top.S;
      for (int i = 0; i < 4; i++)
      {
        int nY = y + mY[i], nX = x + mX[i];
        if (isValid(nY, nX) && !visited[nY][nX] && reach[nY][nX])
        {
          visited[nY][nX] = true;
          q.push({nY, nX});
        }
      }
    }
    steps++;
  }
  cout << -1 << ENDL;

  return 0;
}