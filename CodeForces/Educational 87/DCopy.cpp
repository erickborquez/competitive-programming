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

int main()
{
  IO;
  int n, q;
  cin >> n >> q;
  vector<pii> v;
  vector<int> queries;
  ///Reasing all the numbers
  FOR(i, 0, n)
  {
    pii aux = {0, -1};
    cin >> aux.F;
    v.pb(aux);
  }

  //Asigning the initial position
  sort(ALL(v));
  FOR(i, 0, n)
  v[i].S = i;

  //Reading all the queries
  FOR(i, 0, q)
  {
    int opt;
    cin >> opt;
    if (opt < 0)
      queries.pb(-opt);
    else
      v.pb(make_pair(opt, -1));
  }
  /// Reasigning position in the array
  sort(ALL(v));
  FOR(i, 1, v.size())
  {
    v[i].S = max(v[i].S, v[i - 1].S);
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