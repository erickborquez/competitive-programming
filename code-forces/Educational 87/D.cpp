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

#define INF 10000000

vector<pii> vc;

struct segmentTree
{
  vector<pii> t[4000000];
  void build(int v, int tl, int tr)
  {
    if (tl == tr)
    {
      t[v] = vector<pii>(1, vc[tl]);
    }
    else
    {
      int tm = (tl + tr) / 2;
      build(v * 2, tl, tm);
      build(v * 2 + 1, tm + 1, tr);
      merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(),
            back_inserter(t[v]));
    }
  }

  pii query(int v, int tl, int tr, int l, int r, int x)
  {
    if (l > r)
      return {INF, INF};
    if (l == tl && r == tr)
    {
      vector<pii>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
      if (pos != t[v].end())
        return *pos;
      return {INF, INF};
    }
    int tm = (tl + tr) / 2;
    return min(query(v * 2, tl, tm, l, min(r, tm), x),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x));
  }

  void update(int v, int tl, int tr, int pos, int new_val)
  {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr)
    {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
    }
    else
    {
      a[pos] = new_val;
    }
  }
};

int main()
{
  IO;
  int n, q;
  cin >> n >> q;
  vector<int> queries;
  ///Reasing all the numbers
  FOR(i, 0, n)
  {
    pii aux = {0, -1};
    cin >> aux.F;
    vc.pb(aux);
  }

  //Asigning the initial position
  sort(ALL(vc));
  FOR(i, 0, n)
  vc[i].S = i;

  //Reading all the queries
  FOR(i, 0, q)
  {
    int opt;
    cin >> opt;
    if (opt < 0)
      queries.pb(-opt);
    else
      vc.pb(make_pair(opt, -1));
  }
  /// Reasigning position in the array
  sort(ALL(vc));
  FOR(i, 1, vc.size())
  {
    vc[i].S = max(vc[i].S, vc[i - 1].S);
  }

  /*
  -- > Debug
  for (auto p : v)
  {
    debp(p.F, p.S);
  }
  */

  return 0;
}