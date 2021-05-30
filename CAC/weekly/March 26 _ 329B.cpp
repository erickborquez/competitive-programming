#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
using namespace std;

string m[2000];
int movesY[4] = {-1, 0, 1, 0};
int movesX[4] = {0, 1, 0, -1};
int r, c;
pair<int, int> start;
pair<int, int> ex;
vector<pair<pair<int, int>, int>> trainers;
int dist[2000][2000];

bool isValidPos(pair<int, int> pos)
{
  int y = pos.F, x = pos.S;
  if (y < 0 || y >= r || x < 0 || x >= c || m[y][x] == 'T')
    return false;
  return true;
}

void bfs()
{
  queue<pair<int, int>> s;
  pair<int, int> actual, next;
  s.push(ex);
  dist[ex.F][ex.S] = 0;
  while (!s.empty())
  {
    actual = s.front();
    s.pop();
    for (int i(0); i < 4; i++)
    {
      next = {actual.F + movesY[i], actual.S + movesX[i]};
      if (isValidPos(next))
      {
        if (dist[next.F][next.S] == -1)
        {
          dist[next.F][next.S] = dist[actual.F][actual.S] + 1;
          s.push(next);
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> r >> c;
  for (int i(0); i < r; i++)
    cin >> m[i];
  for (int i(0); i < r; i++)
    for (int j(0); j < c; j++)
    {
      dist[i][j] = -1;
      char cell = m[i][j];
      if (cell == 'S')
        start = {i, j};
      else if (cell == 'E')
        ex = {i, j};
      else if (cell > '0' && cell <= '9')
        trainers.pb({{i, j}, cell - '0'});
    }

  bfs();

  int MIN = dist[start.F][start.S];
  lli total = 0;
  for (auto t : trainers)
  {
    int d = dist[t.F.F][t.F.S];
    if (d == -1)
      continue;
    if (d <= MIN)
      total += t.S;
  }
  cout << total << ENDL;

  return 0;
}