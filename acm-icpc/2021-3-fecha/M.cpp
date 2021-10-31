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

const int INF = 1e5;
int king = 1;
int id = 2;

vector<vector<int> > g;
int parent[INF];
// Store the next child to get throne
int dp[INF];

void updateNextInTroneForParent(int u)
{
  // I don't exist
  if (u == -1)
    return;

  // The valud stored on my childs dp
  int v = -1;
  for (int c : g[u])
  {
    v = dp[c];
    if (v != -1)
      break;
  }

  // -1 if everyone is dead
  dp[u] = v;

  // Update the dp for the parent if i was the next in throne and had a parent
  int k = parent[u];
  if (k != -1 && dp[k] == u)
  {
    updateNextInTroneForParent(k);
  }
}

void kill(int u)
{
  // Update the dp for the parent if i was the next in throne and had a parent
  int k = parent[u];
  if (k != -1 && dp[k] == u)
  {
    updateNextInTroneForParent(k);
  }

  cout << dp[1] << ENDL;
}

void addChild(int u)
{
  // Add child to parent
  g[u].pb(id);
  parent[id] = u;

  // Next in throne iff only child
  if (g[u].size() == 1)
    dp[u] = id;

  // Increment id
  id++;
}

void init()
{
  FOR(i, 0, INF)
  {
    parent[i] = -1;
    dp[i] = -1;
  }

  g[0].pb(1);
  dp[1] = 1;
}

int main()
{
  IO;
  init();
  // int n;
  // cin >> n;
  // g = vector<vector<int> >(INF, vector<int>());

  // FOR(i, 0, n)
  // {
  //   int q, u;
  //   cin >> q >> u;
  //   if (q == 1)
  //   {
  //     // addChild(u);
  //   }
  //   else
  //   {
  //     // kill(u);
  //     cout << king << ENDL;
  //   }
  // }

  cout << "??" << ENDL;

  return 0;
}