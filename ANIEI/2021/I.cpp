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

int main()
{
  IO;
  string s, t;
  int k;
  while (cin >> s >> t >> k)
  {
    bool ok = false;
    set<string> st;
    FOR(i, 0, s.size() - k + 1)
    {
      string u = s.substr(i, k);
      st.insert(u);
    }

    FOR(i, 0, t.size() - k + 1)
    {
      string u = t.substr(i, k);
      if (st.count(u) == 1)
      {
        ok = true;
        break;
      }
    }
    if (ok)
      cout << "yes" << ENDL;
    else
      cout << "no" << ENDL;
  }
  return 0;
}