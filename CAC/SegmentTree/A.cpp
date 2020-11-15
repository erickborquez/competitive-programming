#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define vi vector<int>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

const int MAXN = 2 * 1e5;
const int INF = 1e9;

struct SegmentTree
{
  int tam;
  vector<pii> mn, mx;

  void pull(int nodo)
  {
    mn[nodo] = min(mn[(nodo * 2) + 1], mn[(nodo * 2) + 2]);
    mx[nodo] = max(mx[(nodo * 2) + 1], mx[(nodo * 2) + 2]);
  }

  void build(vi &vec, lli nodo, lli l, lli r)
  {
    if (r - l == 1)
    {
      if (l < vec.size())
      {
        mn[nodo] = {vec[l], l};
        mx[nodo] = {vec[l], l};
      }
      return;
    }
    lli m = (l + r) / 2;
    build(vec, (nodo * 2) + 1, l, m);
    build(vec, (nodo * 2) + 2, m, r);
    pull(nodo);
  }

  void build(vi &vec)
  {
    build(vec, 0, 0, tam);
  }

  SegmentTree(int n, vi &vec)
  {
    tam = 1;
    while (tam < n)
      tam *= 2;
    mn.assign(2 * tam, {INF, -1});
    mx.assign(2 * tam, {-INF, -1});
    build(vec);
  }

  /// Queries (l, r) l hasta r - 1 querie(0, 1);
  // void update(int pos, lli val, lli nodo, lli l, lli r)
  // {
  //   if (r - l == 1)
  //   {
  //     st[nodo] = val;
  //     return;
  //   }
  //   lli m = (l + r) / 2;
  //   if (pos < m)
  //     update(pos, val, (nodo * 2) + 1, l, m);
  //   else
  //     update(pos, val, (nodo * 2) + 2, m, r);
  //   st[nodo] = st[(nodo * 2) + 1] + st[(nodo * 2) + 2];
  // }

  // void update(int pos, lli val)
  // {
  //   update(pos, val, 0, 0, tam);
  // }

  pii mnQuery(lli nodo, lli l, lli r, lli ll, lli rr)
  {
    if (rr <= l or ll >= r)
      return {INF, -1};

    if (l <= ll and rr <= r)
      return mn[nodo];
    ﻿

        lli m = (ll + rr) / 2;
    pii left = mnQuery((nodo * 2) + 1, l, r, ll, m);
    pii right = mnQuery((nodo * 2) + 2, l, r, m, rr);
    return min(left, right);
  }

  pii mnQuery(lli l, lli r)
  {
    return mnQuery(0, l, r, 0, tam);
  }

  pii mxQuery(lli nodo, lli l, lli r, lli ll, lli rr)
  {
    if (rr <= l or ll >= r)
      return {-INF, -1};

    if (l <= ll and rr <= r)
      return mx[nodo];

    lli m = (ll + rr) / 2;
    pii left = mxQuery((nodo * 2) + 1, l, r, ll, m);
    pii right = mxQuery((nodo * 2) + 2, l, r, m, rr);
    return max(left, right);
  }

  pii mxQuery(lli l, lli r)
  {
    return mxQuery(0, l, r, 0, tam);
  }
};

int main()
{
  IO;
  lli n, m, l, r, x;
  cin >> n >> m;
  vi v(n);
  FOR(i, 0, n)
  {
    cin >> v[i];
  }
  SegmentTree segtree(n, v);
  FOR(i, 0, m)
  {
    cin >> l >> r >> x;
    l--;
    r--;
    // cout << segtree.query(l, r) << ENDL;

    pii mn = segtree.mnQuery(l, r + 1);
    pii mx = segtree.mxQuery(l, r + 1);
    if (mn.F != x)
    {
      cout << mn.S + 1 << ENDL;
    }
    else if (mx.F != x)
    {
      cout << mx.S + 1 << ENDL;
    }
    else
    {
      cout << -1 << ENDL;
    }
    // debp(mn.F, mn.S);
    // debp(mx.F, mx.S);
    // cout << ENDL;
  }
  return 0;
}