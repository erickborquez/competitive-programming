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
  int tc;
  cin >> tc;
  while (tc--)
  {
    string t;
    cin >> t;
    bool one = true, zero = true;
    FOR(i, 0, t.size())
    {
      if (t[i] == '1')
        zero = false;
      else
        one = false;
    }
    if (one || zero)
      cout << t << ENDL;

    else
    {
      char last = t[0];
      cout << last;
      FOR(i, 1, t.size())
      {
        if (t[i] == last)
        {
          if (last == '0')
            cout << '1';
          else
            cout << '0';
        }
        cout << t[i];
        last = t[i];
      }
      cout << ENDL;
    }
  }
  return 0;
}