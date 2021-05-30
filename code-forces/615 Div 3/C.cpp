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
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

vector<bool> isPrime(10000000, true);
vector<lli> primes;

void initCriba()
{
  for (lli i(2); i < 10000000; i++)
    if (isPrime[i])
    {
      // cout << "?" << ENDL;
      primes.pb(i);
      for (lli j = i; j * i < 10000000; j++)
        isPrime[j * i] = false;
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
    lli n;
    cin >> n;
    map<lli, lli> num;
    lli aux = n;
    for (auto p : primes)
    {
      if (aux == 1)
        break;
      while (aux % p == 0)
      {
        num[p]++;
        aux /= p;
        // deb(aux);
      }
      if (p > aux)
      {
        break;
        // debp(p, aux);
      }
    }
    // deb(aux);
    lli first = 1, second = 1, third = 1;
    bool empty = false;

    while (!empty)
    {
      empty = true;
      for (auto p : num)
      {
        if (p.S > 0)
          empty = false;
        if (first == 1)
        {
          first = p.F;
          num[p.F]--;
        }
        else if ((second == 1 || second == first) && p.S > 0)
        {
          second *= p.F;
          num[p.F]--;
        }
        else if (p.S > 0)
        {
          third *= p.F;
          num[p.F]--;
        }
      }
    }

    // third *= aux;
    // deb(third);
    // deb(aux);
    third = third * aux;
    if (first != second && second != third && first != third && first != 1 && second != 1 && third != 1)
    {
      cout << "YES" << ENDL;
      cout << first << " " << second << " " << third << ENDL;
    }
    else
    {
      cout << "NO" << ENDL;
    }
  }
  return 0;
}