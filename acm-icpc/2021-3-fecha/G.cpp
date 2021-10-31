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

const ll MX = 1e17;
vector<ll> fib;

void calc()
{
  fib.pb(1);
  fib.pb(2);
  while (fib[fib.size() - 1] < MX)
  {
    fib.pb(fib[fib.size() - 1] + fib[fib.size() - 2]);
  }
}

int main()
{
  IO;
  ll n;
  calc();
  cin >> n;
  vector<ll> v;
  for (ll i = fib.size() - 1; i > 0; i--)
  {

    while (n % fib[i] == 0)
    {
      v.pb(i);
      n /= fib[i];
    }
  }

  if (n != 1)
  {
    cout << "IMPOSSIBLE" << ENDL;
    return 0;
  }

  for (auto e : v)
  {
    FOR(i, 0, e)
    {
      cout << "A";
    }
    cout << "B";
  }
  cout << ENDL;

  return 0;
}