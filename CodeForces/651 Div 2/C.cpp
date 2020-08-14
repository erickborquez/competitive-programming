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

const lli INF = 1e5;

vector<int> primes;
bool isNotPrime[INF];
void criba()
{
  for (lli i = 2; i < INF; i++)
  {
    if (!isNotPrime[i])
    {
      primes.pb(i);
      for (lli j = i; j * i < INF; j++)
        isNotPrime[i * j] = true;
    }
  }
}

int main()
{
  IO;
  int tc;
  cin >> tc;
  criba();

  while (tc--)
  {
    lli n;
    cin >> n;
    if (n == 1)
      cout << "FastestFinger" << ENDL;
    else if (n == 2 || n % 2)
      cout << "Ashishgup" << ENDL;
    else
    {
      if (__builtin_popcount(n) == 1)
        cout << "FastestFinger" << ENDL;
      else if (n % 4 == 0)
        cout << "Ashishgup" << ENDL;
      else if (n / 2 < INF)
      {
        if (isNotPrime[n / 2])
        {
          cout << "Ashishgup" << ENDL;
          continue;
        }
        bool isPrime = false;
        for (auto p : primes)
          if ((n / 2) % p == 0)
          {
            isPrime = true;
            break;
          }
        if (isPrime)
          cout << "FastestFinger" << ENDL;
        else
          cout << "Ashishgup" << ENDL;
      }

      else
        cout << "FastestFinger" << ENDL;
    }
  }
  return 0;
}