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
  string s;
  cin >> s;
  char n = s[0];
  if (s.size() > 1)
  {
    if (s[1] >= '5')
    {
      cout << s[0] - '0' + 1;
    }
    else
      cout << s[0];
    FOR(i, 1, s.size())
    cout << 0;
    cout << ENDL;
  }
  else
  {
    cout << s << ENDL;
  }

  return 0;
}