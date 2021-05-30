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
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

#define INF 300000

vector<lli> primes;
vector<int> divisor(INF, -1);

void initCriba()
{
  for (lli i(2); i < INF; i++)
  {
    if (divisor[i] == -1)
    {
      primes.pb(i);
      for (lli j = 1; j * i < INF; j++)
      {
        divisor[j * i] = i;
      }
    }
  }
}

int main()
{
  IO;
  initCriba();
  lli n;
  cin >> n;
  vector<lli> v(n);
  map<lli, vector<lli>> m;
  FOR(i, 0, n)
  cin >> v[i];
  for (auto num : v)
  {
    map<lli, lli> local;
    // deb(num);
    while (num != 1)
    {
      lli prime = divisor[num];
      local[prime]++;
      num /= prime;
    }
    for (auto p : local)
    {
      m[p.F].pb(p.S);
      // debp(p.F, p.S);
    }
  }
  lli res = 1;
  for (auto p : m)
  {
    // debp(p.F, p.S.size());
    sort(ALL(p.S));
    lli times = 0;
    if (p.S.size() == n)
      times = p.S[1];
    else if (p.S.size() == n - 1)
      times = p.S[0];
    FOR(i, 0, times)
    res *= p.F;
  }
  cout << res << ENDL;

  return 0;
}