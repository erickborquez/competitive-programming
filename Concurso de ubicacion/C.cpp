#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define INF 10000001

using namespace std;

bool criba[INF];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int primes = 0;
  cin >> n;

  for (int i(2); primes < n; i++)
  {
    if (!criba[i])
    {
      cout << i << " ";
      primes++;
      for (int j(2); j * i < INF; j++)
      {
        criba[j * i] = true;
      }
    }
  }
  return 0;
}