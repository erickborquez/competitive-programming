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
  int n, m;
  char begin;
  int step = 0;
  while (cin >> n)
  {
    if (n == -1)
    {
      break;
    }

    step++;
    cin >> m >> begin;
    vector<ll> pot;
    ll c = n;

    ll ac = 1;
    vector<ll> calc;

    while (c > 0)
    {
      pot.pb(c % 2);
      if (c % 2)
      {
        calc.pb(ac);
      }
      c /= 2;
      ac *= 2;
    }

    if (begin == 'b')
      reverse(calc.begin(), calc.end());

    cout << "Case " << step << ": " << n << " x " << m << " = ";
    if(n == 0 || m == 0) {
      cout << "0" <<ENDL;
    } else {

    FOR(i, 0, calc.size())
    {
      cout << calc[i] * m;
      if (i < calc.size() - 1)
        cout << " + ";
    }
    cout << ENDL;
    }
  }
  return 0;
}