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

vector<vector<int>> t;
vector<lli> v;
vector<int> h;
vector<vector<pair<int, lli>>> q;
int mxHeight;

void dfs(int u, int p, map<int, lli> &vc)
{
  v[u] = v[p];
  auto left = vc.lower_bound(h[u] - 1);
  auto right = vc.upper_bound(h[u] - 1);
  while (left != right)
  {
    v[u] -= (*left).S;
    left++;
  }
  for (auto k : q[u])
  {
    vc[min(mxHeight, h[u] + k.F)] += k.S;
    v[u] += k.S;
  }
  for (auto k : t[u])
  {
    if (k != p)
      dfs(k, u, vc);
  }
  for (auto k : q[u])
  {
    int pos = min(mxHeight, h[u] + k.F);
    vc[pos] -= k.S;
    if (vc[pos] == 0)
      vc.erase(pos);
  }
}

int getHeight(int u, int p)
{
  h[u] = h[p] + 1;
  int mx = h[u];
  for (auto k : t[u])
    if (k != p)
      mx = max(mx, getHeight(k, u));
  return mx;
}

int main()
{
  IO;
  int n, m;
  cin >> n;
  t = vector<vector<int>>(n + 1);
  v = vector<lli>(n + 1, 0);
  h = vector<int>(n + 1, -1);
  q = vector<vector<pair<int, lli>>>(n + 1);
  FOR(i, 1, n)
  {
    int from, to;
    cin >> from >> to;
    t[from].pb(to);
    t[to].pb(from);
  }
  cin >> m;
  lli u, d, x;
  FOR(i, 0, m)
  {
    cin >> u >> d >> x;
    q[u].pb({d, x});
  }
  mxHeight = getHeight(1, 1);
  map<int, lli> mp;
  dfs(1, 1, mp);
  FOR(i, 1, n + 1)
  {
    cout << v[i] << " ";
  }

  return 0;
}