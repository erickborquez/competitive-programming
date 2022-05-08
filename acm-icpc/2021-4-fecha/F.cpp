#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ll long long
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

map<char, int> movesY, movesX;
int r, c, e;

void init()
{
  movesY['N'] = -1;
  movesY['S'] = 1;
  movesY['E'] = 0;
  movesY['W'] = 0;

  movesX['N'] = 0;
  movesX['S'] = 0;
  movesX['E'] = 1;
  movesX['W'] = -1;
}

bool isValid(int x, int y)
{
  return !(x < 0 || x >= c || y < 0 || y >= r);
}
vector<string> m;
vector<vector<int> > moves;

pair<int, int> moveTo(int x, int y, int step)
{
  // debp(x, y);
  // deb(step);
  moves[y][x] = step;
  char sensor = m[y][x];
  int nX = x + movesX[sensor];
  int nY = y + movesY[sensor];

  if (isValid(nX, nY))
  {
    if (moves[nY][nX] != -1)
    {
      int start = moves[nY][nX] - 1;
      int duration = step - start;
      return make_pair(start, duration);
    }
    return moveTo(nX, nY, step + 1);
  }
  else
  {
    return make_pair(step + 1, -1);
  }
}

int main()
{
  IO;
  init();
  while (cin >> r >> c >> e)
  {
    //END STEP
    if (r == 0)
      return 0;
    m = vector<string>(r);
    moves = vector<vector<int> >(r, vector<int>(c, -1));
    FOR(i, 0, r)
    {
      cin >> m[i];
    }
    pair<int, int> res = moveTo(e - 1, 0, 1);
    if (res.S == -1)
    {
      cout << res.F - 1 << " step(s) to exit" << ENDL;
    }
    else
    {
      cout << res.F << " step(s) before a loop of " << res.S << " step(s)" << ENDL;
    }
  }
  return 0;
}