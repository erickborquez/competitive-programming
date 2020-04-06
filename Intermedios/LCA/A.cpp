#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define lli long long
#define deb(u) cout << #u ": " << (u) << endl;
#define SIZE 1000000
#define INF -1

using namespace std;

vector<int> euler;
vector<vector<int>> t(SIZE);
bool vis[SIZE];
int first[SIZE];
int height[SIZE];

void addNode(int u, int h)
{
  vis[u] = true;
  first[u] = euler.size();
  euler.pb(u);
  height[u] = h;
  for (auto v : t[u])
  {
    if (!vis[v])
    {
      addNode(v, h + 1);
      euler.pb(u);
    }
  }
}
struct SegmentTree
{
  vector<int> MIN;
  SegmentTree(int n)
  {
    MIN.resize(n * 4);
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      MIN[u] = euler[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
  }

  void pull(int u)
  {
    if (height[MIN[2 * u]] < height[MIN[2 * u + 1]])
    {
      MIN[u] = MIN[2 * u];
    }
    else
    {
      MIN[u] = MIN[2 * u + 1];
    }
  }

  int query(int u, int l, int r, int ll, int rr)
  {
    if (rr < l || r < ll || r < l)
    {
      return INF;
    }
    if (ll <= l && r <= rr)
    {
      return MIN[u];
    }
    int m = (l + r) / 2;
    int left = query(u * 2, l, m, ll, rr);
    int right = query(u * 2 + 1, m + 1, r, ll, rr);
    if (right == INF)
      return left;
    if (left == INF)
      return right;
    if (height[left] < height[right])
      return left;
    return right;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, aux;
  cin >> n;
  for (int i(1); i <= n; i++)
  {
    cin >> m;
    while (m--)
    {
      cin >> aux;
      t[i].pb(aux + 1);
    }
  }
  euler.pb(-1);
  addNode(1, 1);

  SegmentTree st(euler.size() - 1);

  int q, u, v;
  cin >> q;
  while (q--)
  {
    cin >> u >> v;
    u++;
    v++;
    int left = min(first[u], first[v]);
    int right = max(first[u], first[v]);

    cout << st.query(1, 1, euler.size() - 1, left, right) - 1 << ENDL;
  }

  return 0;
}