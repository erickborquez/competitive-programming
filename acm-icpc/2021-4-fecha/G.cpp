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

const int MAX = 1e6 - 1;

vector<int> primes;
bool isPrime[MAX];

void criba()
{
  FOR(i, 0, MAX)
  isPrime[i] = true;

  for (ll i = 2; i < MAX; i++)
  {
    if (isPrime[i])
    {
      primes.pb(i);
      for (ll j = i; i * j < MAX; j++)
      {
        isPrime[i * j] = false;
      }
    }
  }
}

ll sum(ll n)
{
  return (n * n + 1) / 2;
}

ll getApparences(ll u, ll k)
{
  ll res = 0;
  ll c = k;
  while (c <= u)
  {
    res += u / c;
    c *= k;
  }
  return res;
}

ll x, y;

int main()
{
  IO;
  criba();
  int tc;
  cin >> tc;
  while (tc--)
  {
    cin >> x >> y;
    map<ll, ll> multiples;
    lli c = y;

    for (auto p : primes)
    {
      while (p <= c && c % p == 0)
      {
        multiples[p]++;
        c /= p;
      }
    }
    if (c > 1)
    {
      multiples[c]++;
    }
    ll res = 1;
    for (pair<ll, ll> k : multiples)
    {
      ll u = min(k.S, getApparences(x, k.F));
      FOR(i, 0, u)
      {
        res *= k.F;
      }
    }
    cout << res << ENDL;
  }
  return 0;
}