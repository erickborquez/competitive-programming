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
#define pll pair<ld, ld>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

const ld INF = 1e18;

ld getDist(pll a, pll b)
{
  ld fs = a.F - b.F, sc = a.S - b.S;
  return sqrt(fs * fs + sc * sc);
}

ld getArea(pll pta, pll ptb, pll ptc)
{
  ld a = getDist(pta, ptb);
  ld b = getDist(ptb, ptc);
  ld c = getDist(ptc, pta);
  ld sm = (a + b + c) / 2;
  ld area = sqrt(sm * (sm - a) * (sm - b) * (sm - c));
  return area;
}

int main()
{
  IO;
  lli n;
  cin >> n;
  vector<pll> crd(n);

  FOR(i, 0, n)
  cin >> crd[i].F >> crd[i].S;
  ld best = INF;
  FOR(i, 0, n)
  {
    deb(i);
    ld a = i, b = (i + 1) % n, c = (i + 2) % n;

    best = min(best, getArea(crd[a], crd[b], crd[c]));
  }
  debp(best, best * 2);
  best *= 2;
  cout << best << ENDL;

  return 0;
}