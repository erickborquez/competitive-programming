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

vector<int> primes;
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
    int n, k;
    cin >> n >> k;
    // if (k >= n)
    // {
    //   cout << 1 << ENDL;
    //   continue;
    // }
    int copy = n;
    vector<int> divisors;
    for (auto p : primes)
    {
      // deb(p);
      if (p > k)
        break;
      while (copy % p == 0)
      {
        divisors.pb(p);
        copy /= p;
      }
    }
    if (copy > 1)
      divisors.pb(copy);
    int ans = n, div = 1;
    FOR(i, 0, 1 << (divisors.size()))
    {
      int num = 1;
      FOR(j, 0, divisors.size())
      if (i & (1 << j))
        num *= divisors[j];
      if (num <= k)
        ans = min(ans, n / num);
    }
    cout << ans << ENDL;
  }

  return 0;
}