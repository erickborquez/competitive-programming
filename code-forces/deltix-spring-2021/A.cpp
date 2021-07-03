#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
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

int main()
{
  IO;
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    string s;
    cin >> n >> m >> s;
    queue<int> q;
    FOR(i, 0, n)
    {
      if (s[i] != '0')
        continue;

      int left = i == 0 ? 0 : s[i - 1] == '1';
      int right = i == n - 1 ? 0 : s[i + 1] == '1';
      if (left ^ right)
        q.push(i);
    }

    while (!q.empty() && m--)
    {
      int sz = q.size();
      while (sz--)
      {
        int u = q.front();
        q.pop();
        s[u] = '1';
        if (u > 0 && s[u - 1] == '0')
          q.push(u - 1);
        if (u < n - 1 && s[u + 1] == '0')
          q.push(u + 1);
      }

      sz = q.size();
      while (sz--)
      {
        int u = q.front();
        q.pop();

        int left = u == 0 ? 0 : s[u - 1] == '1';
        int right = u == n - 1 ? 0 : s[u + 1] == '1';
        if (left ^ right)
          q.push(u);
      }
    }
    cout << s << ENDL;
  }
  return 0;
}