#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define INF 10000000

#define lli long long

bool isPrime[INF];

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lli n;
  lli x;
  cin >> n;
  set<lli> primes;

  for (lli i(2); i < INF; i++)
    isPrime[i] = true;
  for (lli i(2); i < INF; i++)
  {
    if (isPrime[i])
    {
      primes.insert(i * i);
      for (lli j(2); j * i < INF; j++)
      {
        isPrime[j * i] = false;
      }
    }
  }
  while (n--)
  {
    cin >> x;
    if (primes.count(x))
    {
      cout << "YES" << ENDL;
    }
    else
      cout << "NO" << ENDL;
  }

  return 0;
}