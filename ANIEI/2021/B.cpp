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

const lli MOD = 1000000007;
const lli MAX = 2010;

bool isPrime[MAX];
ll fac[MAX];
ll dp[MAX];
ll modInvDP[MAX];
lli ans[MAX];
vector<lli> primes;
ll x, y;

void criba()
{
  isPrime[0] = false;
  isPrime[1] = false;

  FOR(i, 2, MAX)
  isPrime[i] = true;

  FOR(i, 2, MAX)
  {
    if (isPrime[i])
    {
      primes.pb(i);
      for (lli j = i; j * i < MAX; j++)
      {
        isPrime[i * j] = false;
      }
    }
  }
}

void generateFact()
{

  fac[0] = 1;
  for (ll i = 1; i < MAX; i++)
  {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
}

ll binPow(ll x, ll y)
{
  ll res = 1;
  x = x % MOD;

  while (y > 0)
  {
    if (y & 1)
      res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}

ll modInverse(ll n)
{
  if (modInvDP[n] != -1)
    return modInvDP[n];
  ll k = fac[n];

  modInvDP[n] = binPow(k, MOD - 2);
  return modInvDP[n];
}

ll nCrModPFermat(ll n, ll r)
{

  if (n < r)
    return 0;

  if (r == 0)
    return 1;

  return (fac[n] * modInverse(r) % MOD * modInverse(n - r) % MOD) % MOD;
}

ll calculate(ll k)
{
  if (dp[k] != -1)
    return dp[k];

  dp[k] = 0LL;
  // deb(k);
  for (ll u : primes)
  {
    ll v = k - u;
    if (v < 0 || u > k / 2)
      break;
    if (!isPrime[v])
      continue;
    ll value = nCrModPFermat(u + v, v);
    if (v != u)
      value = value * 2 % MOD;
    dp[k] = (dp[k] + value) % MOD;
  }

  return dp[k];
}

void init()
{
  criba();
  generateFact();

  FOR(i, 0, MAX)
  dp[i] = -1;

  FOR(i, 0, MAX)
  modInvDP[i] = -1;

  FOR(i, 0, MAX)
  ans[i] = 0;
}

void solve()
{
  FOR(i, 1, MAX)
  ans[i] = (ans[i - 1] + calculate(i)) % MOD;
}

int main()
{
  IO;
  init();
  solve();
  int tc;
  cin >> tc;
  while (tc--)
  {
    ll x, y;
    cin >> x >> y;
    lli sol = (ans[y] - ans[x - 1] + MOD) % MOD;
    cout << sol << ENDL;
  }
  return 0;
}