#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ll long long
#define ld long double
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
  int tc;
  cin >> tc;
  while (tc--)
  {
    ll n, c, b, w, r, g;
    cin >> n >> c >> b >> w >> r >> g;
    vector<pll> k;
    k.pb(make_pair(1, b * c));
    k.pb(make_pair(c, r));
    // k.pb(make_pair(c, g));

    ll steps = 0, acc = 0;
    FOR(i, 0, k.size())
    {
      ll rest = n - acc;
      ll take = min(k[i].S, rest);
      steps += take * k[i].F;
      acc += take;
    }
    if (acc == n)
    {
      cout << steps << ENDL;
    }
    else
    {
      cout << "Don't even try!" << ENDL;
    }
  }

  return 0;
}