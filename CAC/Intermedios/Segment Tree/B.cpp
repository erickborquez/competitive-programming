#include <bits/stdc++.h>
#define ENDL '\n'
#define F first
#define S second
#define INF 1000000000

using namespace std;

vector<int> a;

struct SegmentTreeNeg
{
  vector<int> lazy;
  vector<int> MIN;
  SegmentTreeNeg(int n)
  {
    lazy.resize(n * 4);
    MIN.resize(n * 4);
    for (int i(0); i < MIN.size(); i++)
    {
      MIN[i] = 0;
      lazy[1] = 0;
    }
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

  void push(int u, int l, int r)
  {
    if (lazy[u] != 0)
    {
      MIN[u] += lazy[u];
      if (l != r)
      {
        lazy[2 * u] = lazy[u];
        lazy[2 * u + 1] = lazy[u];
      }
      lazy[u] = 0;
    }
  }

  void pull(int u)
  {
    MIN[u] = MIN[2 * u] + MIN[2 * u + 1];
  }

  // int query(int u, int l, int r, int ll, int rr)
  // {
  //   if (rr < l || r < ll || r < l)
  //   {
  //     return 0;
  //   }
  //   if (ll <= l && r <= rr)
  //   {
  //     return MIN[u];
  //   }
  //   int m = (l + r) / 2;
  //   return query(u * 2, l, m, ll, rr) + query(u * 2 + 1, m + 1, r, ll, rr);
  // }
  // void update(int u, int l, int r, int pos, int val)
  // {
  //   if (l == r)
  //   {
  //     MIN[u] = val;
  //     return;
  //   }
  //   int m = (l + r) / 2;
  //   if (pos <= m)
  //   {
  //     update(2 * u, l, m, pos, val);
  //   }
  //   else
  //   {
  //     update(2 * u + 1, m + 1, r, pos, val);
  //   }
  //   pull(u);
  // }
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
      return MIN[u];
    }
    int m = (l + r) / 2;
    return query(2 * u, l, r, ll, rr) + query(2 * u + 1, l, r, ll, rr);
  }
};

struct SegmentTreeZero
{
  vector<int> MIN;
  vector<int> lazy;
  SegmentTreeZero(int n)
  {
    lazy.resize(n * 4);
    MIN.resize(n * 4);
    for (int i(0); i < MIN.size(); i++)
    {
      MIN[i] = 0;
      lazy[1] = 0;
    }
    build(1, 1, n);
  }

  void push(int u, int l, int r)
  {
    if (lazy[u] != 0)
    {
      MIN[u] += lazy[u];
      if (l != r)
      {
        lazy[2 * u] = lazy[u];
        lazy[2 * u + 1] = lazy[u];
      }
      lazy[u] = 0;
    }
  }

  void build(int u, int l, int r)
  {
    if (l == r)
    {
      MIN[u] = a[l] == 0 ? 1 : 0;
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

  // int query(int u, int l, int r, int ll, int rr)
  // {
  //   if (rr < l || r < ll || r < l)
  //   {
  //     return 0;
  //   }
  //   if (ll <= l && r <= rr)
  //   {
  //     return MIN[u];
  //   }
  //   int m = (l + r) / 2;
  //   return query(u * 2, l, m, ll, rr) + query(u * 2 + 1, m + 1, r, ll, rr);
  // }
  // void update(int u, int l, int r, int pos, int val)
  // {
  //   if (l == r)
  //   {
  //     MIN[u] = val;
  //     return;
  //   }
  //   int m = (l + r) / 2;
  //   if (pos <= m)
  //   {
  //     update(2 * u, l, m, pos, val);
  //   }
  //   else
  //   {
  //     update(2 * u + 1, m + 1, r, pos, val);
  //   }
  //   pull(u);
  // }

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
      return MIN[u];
    }
    int m = (l + r) / 2;
    return query(2 * u, l, r, ll, rr) + query(2 * u + 1, l, r, ll, rr);
  }
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, q, l, r;
  char c;
  while (cin >> n >> q)
  {
    vector<int> v(n);
    for (int i(0); i < n; i++)
    {
      cin >> v[i];
    }
    a = v;
    SegmentTreeNeg stn(n);
    SegmentTreeZero st0(n);
    while (q--)
    {
      cin >> c >> l >> r;
      l--;
      r--;
      if (c == 'C')
      {
        r++;
        stn.update(1, 1, n, l, l, r < 0 ? 1 : 0);
        st0.update(1, 1, n, l, l, r == 0 ? 1 : 0);
      }
      else
      {
        if (st0.query(1, 1, n, l, r) > 0)
        {
          cout << '0';
        }
        else
        {
          if (stn.query(1, 1, n, l, r) & 1)
          {
            cout << '-';
          }
          else
          {
            cout << '+';
          }
        }
      }
    }
    cout << ENDL;
  }
  return 0;
}