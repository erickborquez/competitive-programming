#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define pii pair<int, int>
#define lli long long
#define INF 1000000

using namespace std;
vector<string> island;
vector<vector<bool>> visited;
int n, m;

int yMov[2] = {1, 0};
int xMov[2] = {0, 1};

bool isValidPos(pii pos)
{
  int y = pos.F;
  int x = pos.S;
  return !(y < 0 || x < 0 || y >= n || x >= m);
}

bool dfs(pii pos, pii end)
{
  if (pos == end)
    return true;
  pii nextPos;
  for (int i(0); i < 2; i++)
  {
    nextPos = pos;
    nextPos.F += yMov[i];
    nextPos.S += xMov[i];

    if (isValidPos(nextPos) && !visited[nextPos.F][nextPos.S] && island[nextPos.F][nextPos.S] != '#')
    {
      visited[nextPos.F][nextPos.S] = true;
      if (dfs(nextPos, end))
        return true;
    }
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  island.resize(n);
  visited.resize(n);
  for (int i(0); i < n; i++)
  {
    cin >> island[i];
    visited[i].resize(m);
  }
  if (!dfs({0, 0}, {n - 1, m - 1}))
  {
    cout << 0;
    return 0;
  }
  visited[0][0] = false;
  visited[n - 1][m - 1] = false;
  if (dfs({0, 0}, {n - 1, m - 1}))
    cout << 2 << ENDL;
  else
    cout << 1 << ENDL;

  return 0;
}