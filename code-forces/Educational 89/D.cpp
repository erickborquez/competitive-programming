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

#define INF 10000020LL

vector<int> d(INF, -1);

void criba()
{
  for (lli i = 2; i < INF; i++)
  {
    if (d[i] == -1)
    {
      d[i] = i;
      for (lli j = 2; (j * i) < INF; j++)
      {
        d[j * i] = d[j * i] == -1 ? i : d[j * i];
      }
    }
  }
}

int main()
{
  IO;
  int n;
  cin >> n;
  vector<int> v(n);
  FOR(i, 0, n)
  cin >> v[i];
  criba();

  vector<pii> ans;
  for (auto u : v)
  {
    map<int, int> m;
    if (u == d[u])
    {
      ans.pb({-1, -1});
      continue;
    }
    int copy = u;
    while (copy != 1)
    {
      m[d[copy]]++;
      copy /= d[copy];
    }
    if (m.size() == 1)
    {
      ans.pb({-1, -1});
      continue;
    }
    else
    {
      int a = u / d[u], b = d[u];
      // debp(a, b);
      // deb(__gcd(u, a + b));
      while (__gcd(u, (a + b)) != 1 && a > 1 && b > 1)
      {
        b *= d[a];
        a = a / d[a];
      }
      if (a > 1 && b > 1)
        ans.pb({a, b});
      else
        ans.pb({-1, -1});
    }
  }
  for (auto e : ans)
  {
    cout << e.F << " ";
  }
  cout << ENDL;
  for (auto e : ans)
  {
    cout << e.S << " ";
  }
  return 0;
}