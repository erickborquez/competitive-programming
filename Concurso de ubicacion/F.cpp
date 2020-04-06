#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define INF 1000000

#define lli long long

using namespace std;

vector<int> primes;
bool isPrime[INF];

void initCriba()
{

  for (int i(2); i < INF; i++)
  {
    if (!isPrime[i])
    {
      primes.pb(i);
      for (int j(2); i * j < INF; j++)
        isPrime[j * i] = true;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n;
  m = n;
  initCriba();
  vector<pair<int, int>> factors;

  for (auto p : primes)
  {
    if (m % p == 0)
    {
      pair<int, int> f;
      f.F = p;
      f.S = 0;
      while (m % p == 0)
      {
        f.S++;
        m /= p;
      }
      factors.pb(f);
      if (m == 1)
        break;
    }
  }
  vector<int> h;
  h.pb(1);
  while (h[h.size() - 1] < n)
  {
    for (auto &p : factors)
    {
      int last = h[h.size() - 1];
      if (p.S > 0)
      {
        if (p.F * last <= n)
          h.pb(last * p.F);
        p.S--;
      }
    }
  }

  for (int i(h.size() - 1); i >= 0; i--)
  {
    cout << h[i] << " ";
  }
  return 0;
}