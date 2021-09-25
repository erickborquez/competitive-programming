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

int const MAX = 1005;

int n, m;

int mY[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mX[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dp[MAX][MAX];
string board[MAX];

int initializeDP()
{
  FOR(i, 0, MAX)
  FOR(j, 0, MAX)
  dp[i][j] = -1;
}

bool isValid(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}

vector<pair<int, int> > getValidMoves(int x, int y)
{
  vector<pair<int, int> > validMoves;
  FOR(i, 0, 8)
  {

    int newX = x + mX[i];
    int newY = y + mY[i];
    if (isValid(newX, newY))
      validMoves.pb(make_pair(newX, newY));
  }
  return validMoves;
}

int dfs(int x, int y)
{
  if (dp[x][y] != -1)
    return dp[x][y];

  dp[x][y] = 1;

  vector<pair<int, int> > moves = getValidMoves(x, y);
  for (pair<int, int> p : moves)
  {
    if (board[x][y] + 1 == board[p.F][p.S])
    {
      dp[x][y] = max(dp[x][y], dfs(p.F, p.S) + 1);
    }
  }

  return dp[x][y];
}

int main()
{
  IO;
  cin >> n >> m;
  initializeDP();
  FOR(i, 0, n)
  cin >> board[i];

  int best = 1;

  FOR(i, 0, n)
  FOR(j, 0, m)
  best = max(best, dfs(i, j));
  cout << best << ENDL;

  return 0;
}