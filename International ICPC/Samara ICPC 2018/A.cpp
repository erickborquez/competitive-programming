#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
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

const int INF = 1e5;

// vector<int> primes;
// bool isPrime[INF];

// void criba()
// {
//   for (lli i = 0; i < INF; i++)
//     isPrime[i] = true;
//   isPrime[0] = isPrime[1] = false;
//   for (lli i = 2; i < INF; i++)
//   {
//     if (isPrime[i])
//     {
//       primes.pb(i);
//       for (lli j = i; j * i < INF; j++)
//       {
//         isPrime[i * j] = false;
//       }
//     }
//   }
// }

int main()
{
  IO;
  lli s, g;
  cin >> s >> g;
  if (s % g != 0 || s == g || (s - g) % g != 0)
  {
    cout << -1 << ENDL;
    return 0;
  }

  cout << g << " " << s - g << ENDL;

  return 0;
}