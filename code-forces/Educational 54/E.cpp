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

int MX = 3 * 1e5 + 1;
int n, m;

vector<vector<int>> t;
vector<lli> ans;
vector<vector<pair<int, lli>>> q;
vector<lli> acc(MX + 10, 0);

void dfs(int u, int p, int depth, lli k)
{
  k += acc[depth];
  // deb(u);
  for (auto e : q[u])
  {
    k += e.S;
    acc[min(MX, depth + e.F + 1)] += -e.S;
  }
  ans[u] = k;
  for (auto el : t[u])
    if (el != p)
      dfs(el, u, depth + 1, k);
  for (auto e : q[u])
    acc[min(MX, depth + e.F + 1)] += e.S;
}

int main()
{
  IO;
  cin >> n;
  t = vector<vector<int>>(n + 1);
  q = vector<vector<pair<int, lli>>>(n + 1);
  ans = vector<lli>(n + 1);
  FOR(i, 1, n)
  {
    int a, b;
    cin >> a >> b;
    t[a].pb(b);
    t[b].pb(a);
  }
  cin >> m;
  FOR(i, 0, m)
  {
    int u, d, x;
    cin >> u >> d >> x;
    q[u].pb({d, x});
  }
  dfs(1, 1, 0, 0);
  FOR(i, 1, n + 1)
  cout << ans[i] << " ";

  return 0;
}