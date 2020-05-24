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
  int n;
  cin >> n;
  vector<long double> v(n);
  FOR(i, 0, n)
  cin >> v[i];
  sort(ALL(v));
  long double mn = 1;
  bool ok = true;
  for (long double i = 0; i < n; i++)
  {
    if (v[i] > i + 1)
    {
      ok = false;
      break;
    }
    long double frac = v[i] / (i + 1);
    // deb(frac);
    if (frac < mn)
      mn = frac;
  }
  if (!ok)
    cout << "impossible" << ENDL;
  else
    cout << fixed << setprecision(10) << mn << ENDL;
  return 0;
}
