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
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      MIN[u] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
  }

  void pull(int u)
  {
    MIN[u] = min(MIN[2 * u], MIN[2 * u + 1]);
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
    return min(query(u * 2, l, m, ll, rr), query(u * 2 + 1, m + 1, r, ll, rr));
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, q, l, r;
  cin >> n;
  vector<int> v(n);
  for (int i(0); i < n; i++)
  {
    cin >> v[i];
  }
  a = v;
  SegmentTree st(n);
  cin >> q;
  while (q--)
  {
    cin >> l >> r;
    cout << st.query(1, 1, n, l, r) << ENDL;
  }
  return 0;
}