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
  ll b, l;
  cin >> b >> l;
  vector<ll> v(l);
  b++;
  ll acc = 0;
  FOR(i, 0, l)
  {
    cin >> v[i];
    if (i % 2)
      acc = (acc - v[i]) % b;
    else
      acc = (acc + v[i]) % b;
  }

  if (acc % b == 0)
  {
    cout << "0 0" << ENDL;
    return 0;
  }

  ll aRestar = (acc + b) % b;
  ll aSumar = b - aRestar;

  // deb(acc);
  // debp(aSumar, aRestar);
  FOR(i, 0, l)
  {
    if (i % 2 == 0)
    {
      if (v[i] >= aRestar)
      {
        cout << i + 1LL << " " << v[i] - aRestar;
        return 0;
      }
    }
    else
    {
      if (v[i] >= aSumar)
      {
        cout << i + 1LL << " " << v[i] - aSumar;
        return 0;
      }
    }
  }

  cout << "-1 -1" << ENDL;
  return 0;
}