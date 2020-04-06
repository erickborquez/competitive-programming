#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;
bool isPrime[1000000001];
bool relative[1000000001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> primes;
  for (int i(0); i < 1000000001; i++)
    isPrime[i] = true;
  for (int i(2); i < 1000000001; i++)
  {
    if (isPrime[i])
    {
      primes.pb(i);
    }
    for (int j(2); j * i < 1000000001; j++)
    {
      isPrime[j * i] = false;
    }
  }

  int t, n, m;
  lli total;
  while (cin >> n)
  {
    if (n == 0)
      return 0;
    if (isPrime[n])
    {
      cout << n - 1 << ENDL;
      continue;
    }
    m = n;
    set<int> divisors;

    while (n > 1)
    {
      for (auto p : primes)
      {
        while (n % p == 0)
        {
          divisors.insert(p);
          n /= p;
        }
        if (n <= 1)
          break;
      }
    }
    for (int i(2); i < 1000000001; i++)
      relative[i] = true;
    for (auto p : divisors)
    {
      for (int i(1); i * p <= m; i++)
      {
        relative[i * p] = false;
      }
    }
    int t = 0;
    for (int i(2); i < m; i++)
    {
      if (relative[i])
      {
        t++;
      }
    }
    cout << t + 1 << ENDL;
  }
  return 0;
}