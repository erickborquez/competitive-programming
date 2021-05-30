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
  bool isPrime[1000010];
  for (int i(0); i < 1000010; i++)
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
    for (int i(1); i < primes.size(); i++)
    {
      if (isPrime[n - primes[i]])
      {
        cout << n << " = " << primes[i] << " + " << n - primes[i] << ENDL;
        break;
      }
    }
  }
  return 0;
}