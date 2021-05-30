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
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

vector<int> a;

struct SegmentTree
{
  vector<int> damageRatio;
  vector<int> lazy;
  SegmentTree(int n)
  {
    damageRatio.resize(n * 4);
    lazy.resize(n * 4);
    build(1, 1, n);
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      damageRatio[u] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    pull(u);
  }

  void pull(int u)
  {
    damageRatio[u] = damageRatio[2 * u] + damageRatio[2 * u + 1];
  }

  void push(int u, int l, int r)
  {
    if (lazy[u] != 0)
    {
      damageRatio[u] = (l - r + 1) * lazy[u];
      if (l != r)
      {
        lazy[2 * u] = lazy[u];
        lazy[2 * u + 1] = lazy[u];
      }
      lazy[u] = 0;
    }
  }

  void update(int u, int l, int r, int ll, int rr, int val)
  {
    push(u, l, r);
    if (rr < l || r < ll || r < l)
    {
      return;
    }
    if (ll <= l && r <= rr)
    {
      lazy[u] = val;
      push(u, l, r);
    }

    int m = (l + r) / 2;
    update(2 * u, l, m, ll, rr, val);
    update(2 * u + 1, m + 1, r, ll, rr, val);
    pull(u);
  }

  int query(int u, int l, int r, int ll, int rr)
  {
    push(u, l, r);
    if (rr < l || r < ll || r < l)
      return 0;
    if (ll <= l && r <= rr)
    {
      push(u, l, r);
      return damageRatio[u];
    }
    int m = (l + r) / 2;
    return query(2 * u, l, r, ll, rr) + query(2 * u + 1, l, r, ll, rr);
  }
};

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    lli n;
    cin >> n;
    lli a, b, total = 0;
    lli life, dmg;
    vector<pll> nodes(2 * n);
    vector<pll> damage(2 * n, {-1, 0});
    vector<lli> kills(2 * n);

    FOR(i, 0, n)
    {
      cin >> life >> dmg;
      nodes[i] = {life, dmg};
      nodes[n + i] = {life, dmg};
    }
    cout << "---" << ENDL;
    bool cicle = false;
    for (int i = n * 2 - 1, j; i >= 0;)
    {
      damage[i] = {nodes[i].F, nodes[i].F};
      kills[i] = i;
      for (j = i - 1;; j--)
      {
        if (j < 0)
          break;
        if (nodes[j].S >= nodes[j + 1].F)
        {
          if (i - n == j)
          {
            deb(i);
            deb(j);
            cicle = true;
            break;
          }
          kills[j] = i;
          damage[j] = {damage[j + 1].F + nodes[j].F, nodes[j].F};
        }
        else
        {
          break;
        }
      }
      i = j;
    }
    if (cicle)
    {
      cout << "CICLE" << ENDL;
      ////handle cicles
    }
    FOR(i, 0, kills.size())
    {
      debp(i, kills[i]);
    }

    FOR(i, 0, n)
    {
    }
  }
  return 0;
}