#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;

bool isPrime[10000];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> primes;
  for (int i(2); i < 10000; i++)
  {
    if (isPrime[i] == false)
      primes.pb(i);
    for (int j(2); j * i < 10000; j++)
    {
      isPrime[j * i] = true;
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  int aFactor, bFactor;
  while (!(b % a == 0))
  {
    aFactor = 1;
    while (a * aFactor < b)
      aFactor++;
    cout << aFactor;
    bFactor = 1;
  }

  // int t;
  // cin>>t;
  // while(t--){

  // }
  return 0;
}