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
  int n, k;
  cin >> n >> k;
  vector<pii> v(n);
  FOR(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(a - 1, b);
  }

  bool ok = true;
  FOR(i, 0, n)
  {
    if (v[i].first == i || v[i].second == v[v[i].F].S)
      continue;
    ok = false;
    break;
  }
  if (ok)
    cout << "Y" << ENDL;
  else
    cout << "N" << ENDL;

  return 0;
}