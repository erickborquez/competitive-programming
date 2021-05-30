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

lli SQR(lli u)
{
  return u * u;
}

int main()
{
  IO;
  string s;
  cin >> s;
  vector<lli> v;
  char last = s[s.size() - 1];
  int changes = 0;
  lli lastVal = 1;
  v.pb(last == 'H' ? 1 : -1);
  FORN(i, s.size() - 1, 0)
  {
    if (s[i] != last)
    {
      last = s[i];
      lastVal *= 2 * (i + 4);
      v.pb(last == 'H' ? lastVal : -lastVal);
    }
  }
  cout << v.size() - 1 << ENDL;
  for (auto e : v)
  {
    cout << e << " ";
  }
  return 0;
}