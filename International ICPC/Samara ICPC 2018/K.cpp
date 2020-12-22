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
int n, m;
vector<int> v;

bool ok(int u)
{
  int total = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] <= total)
      total++;
    else if (u > 0)
    {
      u--;
      total++;
    }
  }

  return total >= m;
}

int main()
{
  IO;
  cin >> n >> m;
  v.resize(n);
  FOR(i, 0, n)
  cin >> v[i];
  int ptr = -1;
  for (int i = n + 1; i > 0; i /= 2)
  {
    while (!ok(ptr + i))
      ptr += i;
  }
  cout << ptr + 1 << ENDL;

  return 0;
}