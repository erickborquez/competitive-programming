#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define INF 1000000000

using namespace std;

vector<int> a;

struct SegmentTree
{
  vector<int> MIN;
  SegmentTree(int n)
  {
    MIN.resize(n * 4);
    for (int i(0); i < MIN.size(); i++)
      MIN[i] = 0;
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      MIN[u] = a[l] < 0 ? 1 : 0;
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
  }

  void pull(int u)
  {
    MIN[u] = MIN[2 * u] + MIN[2 * u + 1];
  }

  int query(int u, int l, int r, int ll, int rr)
  {
    if (rr < l || r < ll || r < l)
    {
      return 0;
    }
    if (ll <= l && r <= rr)
    {
      return MIN[u];
    }
    int m = (l + r) / 2;
    return query(u * 2, l, m, ll, rr) + query(u * 2 + 1, m + 1, r, ll, rr);
  }
  void update(int u, int l, int r, int pos, int val)
  {
    if (l == r)
    {
      MIN[u] = val;
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
    {
      update(2 * u, l, m, pos, val);
    }
    else
    {
      update(2 * u + 1, m + 1, r, pos, val);
    }
    pull(u);
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n;
  vector<int> v(1 << n);
  for (int i(0); i < v.size(); i++)
  {
    cin >> v[i];
  }
  return 0;
}