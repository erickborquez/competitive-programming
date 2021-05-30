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

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    map<int, int> s;
    FOR(i, 0, n)
    {
      int aux;
      cin >> aux;
      s[aux]++;
    }

    int dis = s.size();
    int mx = -1;
    for (auto p : s)
    {
      mx = max(mx, p.S);
    }
    if (dis == mx)
    {
      cout << dis - 1 << ENDL;
    }
    else
    {
      cout << min(dis, mx) << ENDL;
    }
  }
  return 0;
}