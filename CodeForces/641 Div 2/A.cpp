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

#define INF 1000000

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
  initCriba();
  int t;
  cin >> t;
  while (t--)
  {
    lli n, k;
    cin >> n >> k;
    lli lastPrime = INF;
    while (k--)
    {
      for (auto p : primes)
      {
        if (p >= lastPrime)
          break;
        if (n % p == 0)
        {
          lastPrime = p;
          break;
        }
      }
      n += lastPrime;
      if (lastPrime == 2)
        break;
    }
    if (k > 0)
      n += k * 2;
    cout << n << ENDL;
  }
  return 0;
}