#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define S second
#define F first

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> primes;
  bool isPrime[1000010];
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i(2); i < 1000010; i++)
    isPrime[i] = true;
  for (int i(2); i < 1000010; i++)
  {
    if (isPrime[i])
    {
      primes.pb(i);
    }
    for (int j(2); j * i < 1000010; j++)
    {
      isPrime[j * i] = false;
    }
  }
  int n;
  while (cin >> n)
  {
    if (n == 0)
      return 0;
    int total = 0;
    for (int i(0); i < primes.size(); i++)
    {
      if (primes[i] > n)
        break;
      if (isPrime[n - primes[i]])
      {
        total++;
      }
    }
    cout << total / 2 + total % 2 << ENDL;
  }
  return 0;
}
