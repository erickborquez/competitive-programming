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

#define INF 200000

vector<lli> primes;
bool isNotPrime[INF];

void initCriba()
{
  for (lli i(2); i < INF; i++)
  {
    if (!isNotPrime[i])
    {
      primes.pb(i);
      for (lli j = i; j * i < INF; j++)
        isNotPrime[j * i] = true;
    }
  }
}

int main()
{
  IO;
  int n;
  initCriba();
  cin >> n;
  vector<lli> v(n);

  map<int, vector<int>> divisors;
  FOR(i, 0, n)
  cin >> v[i];
  if (n == 1)
  {
    cout << v[0] << ENDL;
    return 0;
  }

  FOR(i, 0, n)
  {
    lli num = v[i];
    map<int, int> newMap;
    for (auto p : primes)
    {
      if (num == 1)
        break;
      while (num % p == 0)
      {
        num /= p;
        newMap[p]++;
      }
    }
    for (auto pi : newMap)
    {
      divisors[pi.F].pb(pi.S);
    }
  }
  lli res = 1;
  for (auto pv : divisors)
  {
    if (pv.S.size() >= n - 1)
    {
      sort(ALL(pv.S));
      int pot = pv.S[1];
      FOR(i, 0, pot)
      res *= pv.F;
    }
  }
  cout << res << ENDL;

  return 0;
}