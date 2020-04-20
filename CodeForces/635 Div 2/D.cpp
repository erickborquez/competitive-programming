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
#define INF 1999999996000000002LL

lli nr, ng, nb;
vector<lli> r, g, b;

lli okB(lli rVal, lli gVal, lli it)
{
  if (it >= nb)
  {
    return INF;
  }
  lli total = (rVal - b[it]) * (rVal - b[it]);
  total += (gVal - b[it]) * (gVal - b[it]);
  total += (rVal - gVal) * (rVal - gVal);
  return total;
}

lli okG(lli rVal, lli it)
{
  if (it >= ng)
    return INF;

  lli pos = 0;
  for (lli i = nb - 1; i > 0; i /= 2)
  {
    while ((pos + i) < nb && okB(rVal, g[it], pos + i) >= okB(rVal, g[it], pos + i + 1))
    {
      pos += i;
    }
  }
  lli total = min(okB(rVal, g[it], pos), okB(rVal, g[it], pos + 1));
  return total;
}

int main()
{
  IO;
  lli t;
  cin >> t;
  while (t--)
  {
    cin >> nr >> ng >> nb;
    r = vector<lli>(nr);
    g = vector<lli>(ng);
    b = vector<lli>(nb);
    FOR(i, 0, nr)
    cin >> r[i];
    FOR(i, 0, ng)
    cin >> g[i];
    FOR(i, 0, nb)
    cin >> b[i];
    sort(ALL(r));
    sort(ALL(g));
    sort(ALL(b));
    // lli best = (r[0] - g[0]) * (r[0] - g[0]) + (r[0] - b[0]) * (r[0] - b[0]) + (g[0] - b[0]) * (g[0] - b[0]);
    lli best = INF;

    FOR(i, 0, nr)
    {
      lli it = 0;
      for (lli j = ng - 1; j > 0; j /= 2)
      {
        while ((it + j) < ng && okG(r[i], it + j) >= okG(r[i], it + j + 1))
        {
          it += j;
        }
      }
      lli total = min(okG(r[i], it), okG(r[i], it + 1));
      best = min(total, best);
    }
    cout << best << ENDL;
  }
  return 0;
}