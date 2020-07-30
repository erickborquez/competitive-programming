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

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> light(n, false);
    FOR(i, 0, n)
    {

      if (s[i] == '*')
      {
        if (i > 0)
          light[i - 1] = true;
        light[i] = true;
        if (i < n - 1)
          light[i + 1] = true;
      }
    }
    int c = 0;
    FOR(i, 0, n)
    {
      if (light[i] == false)
      {
        c++;
        light[i] = true;
        if (i < n - 1)
          light[i + 1] = true;
        if (i < n - 2)
          light[i + 2] = true;
      }
    }
    cout << c << ENDL;
  }
  return 0;
}