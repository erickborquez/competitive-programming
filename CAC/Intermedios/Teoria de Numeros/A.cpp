#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> primes;
  bool isPrime[500001];
  for (int i(0); i < 500001; i++)
    isPrime[i] = true;
  for (int i(2); i < 500001; i++)
  {
    if (isPrime[i])
    {
      primes.pb(i);
    }
    for (int j(2); j * i < 500001; j++)
    {
      isPrime[j * i] = false;
    }
  }
  int t, n, m;
  lli total;
  cin >> t;
  while (t--)
  {
    total = 1;
    cin >> n;
    m = n;

    map<int, int> divisors;

    while (n > 1)
    {
      for (auto p : primes)
      {
        while (n % p == 0)
        {
          divisors[p]++;
          n /= p;
        }
        if (n <= 1)
          break;
      }
    }
    for (auto p : divisors)
    {
      int localTotal = 0;
      for (int i(0); i <= p.S; i++)
      {
        int pot = 1;
        localTotal += pow(p.F, i);
      }
      total *= localTotal;
    }
    cout << total - m << ENDL;
  }
  return 0;
}