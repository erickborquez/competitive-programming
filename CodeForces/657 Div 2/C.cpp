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

#define INF 100000000
int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    lli n, m;
    cin >> n >> m;
    vector<pll> v(m), b(m);
    vector<bool> taken(m, 0);
    FOR(i, 0, m)
    {
      cin >> v[i].F >> v[i].S;
    }

    sort(v.rbegin(), v.rend());
    FOR(i, 0, m)
    {
      b[i] = {v[i].S, i};
    }
    sort(b.rbegin(), b.rend());
    lli bestTaken = 0;
    lli total = 0;
    lli ptr = 0;
    lli bPtr = 0;
    while (true)
    {

      if (n == 0)
        break;
      if (ptr >= m)
      {
        total += bestTaken * n;
        break;
      }
      lli vVal = v[ptr].F;
      while (taken[b[bPtr].S])
        bPtr++;
      // deb(n);
      // deb(ptr);
      // deb(bPtr);
      // deb(bestTaken);
      lli bVal = b[bPtr].F * (n - 1) + v[b[bPtr].S].F;

      if (bestTaken > vVal && bestTaken * n > bVal)
      {
        total += bestTaken * n;
        break;
      }
      else if (vVal * n > bVal)
      {
        total += vVal;
        bestTaken = max(v[ptr].S, bestTaken);
        taken[ptr] = true;
        ptr++;
        n--;
      }
      else
      {
        total += bVal;
        break;
      }
    }
    cout << total << ENDL;
  }
  return 0;
}