#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
#define pii pair<int, int>
using namespace std;

vector<int> a;

struct SegmentTree
{
  vector<pair<bool, int>> node;
  int last = 0;
  SegmentTree(int n)
  {
    node.resize(n * 4);
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      last = max(r, last);
      if (a[l] == 0)
        node[u] = {true, a[l]};
      else
        node[u] = {false, a[l]};
      // cout << u << ":" << node[u].S << ENDL;
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
    // cout << u << ":" << node[u].S << ENDL;
  }

  void pull(int u)
  {
    int sum = node[2 * u].S + node[2 * u + 1].S;
    bool hasZeros = node[2 * u].F || node[2 * u + 1].F || sum == 0;
    node[u] = {hasZeros, sum};
  }

  pair<bool, int> query(int u, int l, int r, int ll, int rr)
  {
    if (rr < l || r < ll || r < l)
    {
      return {false, 0};
    }
    if (ll <= l && r <= rr)
    {
      return node[u];
    }
    int m = (l + r) / 2;
    pair<bool, int> left = query(u * 2, l, m, ll, rr);
    pair<bool, int> right = query(u * 2 + 1, m + 1, r, ll, rr);
    int sum = left.S + right.S;
    bool isZero = left.F || right.F || (sum == 0);
    return {isZero, sum};
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  a.resize(n + 1);
  a[0] = 0;
  bool allZeros = true;
  for (int i(1); i <= n; i++)
  {
    cin >> a[i];
    if (a[i] != 0)
      allZeros = false;
  }
  if (allZeros)
    cout << 0 << ENDL;
  SegmentTree st(n);
  int totalNodes;
  if (n % 2 == 1)
  {
    totalNodes = (n + 1) / 2;
    totalNodes *= n;
  }
  else
  {
    totalNodes = n / 2;
    totalNodes *= n + 1;
  }
  int total = 0;
  for (int i(1); i < n + 1; i++)
  {
    for (int j(i); j < n + 1; j++)
    {
      if (st.query(1, 1, n, i, j).F)
        total++;
    }
  }
  cout << totalNodes - total << ENDL;
  return 0;
}